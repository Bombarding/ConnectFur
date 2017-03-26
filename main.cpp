/* Created By Alex Steel
 * Using Jetbrains CLion IDE
 * A game of connect four for Ankur Gupta's C++ Class
 */
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Creating a list of function declerations for the game of connect 4
//Creation is a Function that Draws the Board.
//Human is a Function that Handles the Human Move
//Computer is a Function that Handles the Computer Move
//Veritcal is a Function That Checks for Vertical Win
//Horizontal is a Function That Checks for Horizontal Win
//Diagonal is a Function That Checks for Diagonal Win
//TieGame is a Function That Checks for a Tie Game
//CheckTehBoard is a Function for Computer to Check for Win or Loss
//CheckTehMoves is a Function to Check if Computer Move Will Allow Human to Win

void Creation(ostream &, char [][7], int8_t, int8_t);
int8_t Human(ostream & out, bool player, char board[][7], int8_t rows, int8_t columns);
int8_t Computer(ostream & out, int8_t diff, bool player, char board[][7], int8_t rows, int8_t columns);
bool Vertical(char board[][7], int8_t rows, int8_t columns, int8_t moverow, int8_t movecolumn);
bool Horizontal(char board[][7], int8_t rows, int8_t columns, int8_t moverow, int8_t movecolumn);
bool Diagonal(char board[][7], int8_t rows, int8_t columns, int8_t moverow, int8_t movecolumn);
bool TieGame(char board[][7], int8_t rows, int8_t columns);
int8_t CheckTehBoard(char symbol, char board[][7], int8_t rows, int8_t columns);
int8_t * CheckTehMoves(char symbol, char board[][7],int8_t rows, int8_t columns);

int main()
{
    int NumberOfPlayers;
    //Computer Difficulty Level, Will be 1, 2, or 3
    int8_t Difficulty;
    //Whether Player has Won, or Quit
    int8_t CharlieSheen = 0;//CharlieSheen is the var 'win'
    bool FullMetal = 1;//FullMetal is the var 'player'
    bool WhoGoesFirst; //Human or computer?
    char Board [6][7] = {0}; //Filling the game board
    ofstream OutPutFile; //Prints results to specified File
    OutPutFile.open("GameLog.txt");

    //Creating a menu for the game
    cout << "Welcome to the not so simple game of connect fur." << endl;
    cout << "How many players will be playing today??" << endl;
    //initialize a loop until User selects how many players will be playing
    do
    {
        cout << "Please Enter an Integer Value Between 0 and 2." << endl;
        cout << "0 is CvC. 1 is PvC. 2 is PvP" << endl;
        cin >> NumberOfPlayers;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
    }while(NumberOfPlayers < 0 || NumberOfPlayers > 2);

    //Starting the game if User selects a valid player Count
    if(NumberOfPlayers < 2)
    {
        //Creating a Random Number Generator
        srand(time(NULL));
        int BadInputVariable;
        cout<<"\nPlease Select The Difficulty of the Computer."<<endl;
        //Selecting a Difficulty Level, Assuming all other conditions have been met so far.
        do
        {
            cout<<"Press: 1 Fur Easy. 2 Fur Medium. 3 Fur Hard xD" << endl;
            cin>>BadInputVariable;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        }
        while (BadInputVariable < 1 || BadInputVariable > 3);
        Difficulty = BadInputVariable; //Set Difficulty Level For the Game Here on Out.
        //Setting the PvC Case
        if (NumberOfPlayers == 1)
        {
            int LikelyInputVariable;
            cout<<"\nWould you like to go first. Program? Yes, this is Tron. Ping Pong."<<endl;
            do
            {
                cout<<"Press: 0 Fur No. 1 Fur Yass";
                cin>>LikelyInputVariable;
            }
            while (LikelyInputVariable < 0 || LikelyInputVariable > 1);
            WhoGoesFirst = LikelyInputVariable; //Pick who Goes First
        }
    }
    //Draw Board, Initialize With "-" Simple Board, But a Board None the Less.
    for (int8_t x = 0; x < 6; x++)
    {
        for (int8_t y = 0; y < 7; y++)
        {
            Board[x][y] = '-';
        }
    }
    cout<<"\n[&&] Woot Woot! Game Start! [%%]"<<endl;
    OutPutFile<<"[**] Woot Woot! Game Start! [$$]"<<endl;

    //Basically means the game is not finished yet
    while(CharlieSheen == 0)
    {
        Creation(cout, Board, 6, 7);
        Creation(OutPutFile, Board, 6, 7);
        //^= utilizing XOR, Switch from p1 to p2
        FullMetal ^= 1;
        //statement that moves depending on NumberOfPlayers
        switch(NumberOfPlayers)
        {
            case 0: //No HooMan
                CharlieSheen = Computer(OutPutFile, Difficulty, FullMetal, Board, 6, 7);
                break;
            case 1://1 HooMan
                if(FullMetal == WhoGoesFirst)
                    CharlieSheen = Computer(OutPutFile, Difficulty, FullMetal, Board, 6, 7);
                else
                    CharlieSheen = Human(OutPutFile, FullMetal, Board, 6, 7);
                break;
            case 2: //2 HooMan
                CharlieSheen = Human(OutPutFile, FullMetal, Board, 6, 7);
                break;
            default:
                CharlieSheen = -1;
                break;
        }
    }
    Creation(cout, Board, 6, 7);
    Creation(OutPutFile, Board, 6, 7);

    //Statement that determines winning message
    switch (CharlieSheen)
    {
        case -1: //The Player Decided to Quit The Game
            cout << "\nQuitters Never Prosper\n" << endl;
            OutPutFile << "\nQuitters Never Prosper\n" << endl;
            break;
        case 1: //The Player Decided to Win the Game
            cout << "\nPlayer " << (FullMetal + 1) << " Won!!!!\n" << endl;
            OutPutFile << "\nPlayer " << (FullMetal + 1) << " Won!!!!\n" << endl;
            break;
        case 2: //The Player Was So Smart, We just had to Tie The Game. Sometimes not Playing is
            //The only True way to win. So when masters fight each other, it is always a tie.
            cout << "\nThe Game Has Ended In a Tie.\n" << endl;
            OutPutFile << "\nThe Game Has Ended In a Tie.\n" << endl;
            break;
        default:
            break;
    }
    OutPutFile.close();
    return 0;
}

//Function That handles Creating the board.
void Creation(ostream & out, char b[][7], int8_t Rectangles, int8_t Colors)
{
    out << endl;

    for (int8_t i = 1; i <= Colors; i++) //Display Column Numbers
        out<<(int) i<<" "; //Display as Integers
    out<<"\n"<<endl;
    for (int8_t x = Rectangles-1; x >= 0; x--)  //Output Game Board
    {
        for (int8_t y = 0; y < Colors; y++)
        {
            if (b[x][y] == 0)
                out << "  ";
            else
                out << b[x][y] << " ";
        }
        out << endl;
    }
    out << endl << endl;
}

//Function that handles the human move
int8_t Human(ostream & out, bool FullMetal, char Board[][7], int8_t Rows, int8_t Columns)
{

}

//Function that handles the Computer Move
int8_t Computer(ostream & out, int8_t Difficulty, bool FullMetal, char Board[][7], int8_t Rows, int8_t Columns)
{

}

//Function that handles a Vertical Win
bool Vertical(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn)
{

}
//Function that handles a Horizontal Win
bool Horizontal(char board[][7], int8_t rows, int8_t columns, int8_t moverow, int8_t movecolumn)
{

}
//Function that handles a Diagonal Win
bool Diagonal(char board[][7], int8_t rows, int8_t columns, int8_t moverow, int8_t movecolumn)
{

}
//Function that hadles a TieGame
bool TieGame(char board[][7], int8_t rows, int8_t columns)
{

}
//Function that Checks Teh Board for a win or a loss
int8_t CheckTehBoard(char symbol, char board[][7], int8_t rows, int8_t columns)
{

}
//Function that Checks Teh Moves to allow a Human to win
int8_t * checkmoves(char symbol, char board[][7], int8_t rows, int8_t columns)
{

}