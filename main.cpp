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
int8_t Human(ostream & out, bool Steel, char Board[][7], int8_t Rows, int8_t Columns);
int8_t Computer(ostream & OutPut, int8_t Difficulty, bool FullMetal, char Board[][7], int8_t Rows, int8_t Columns);
bool Vertical(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn);
bool Horizontal(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn);
bool Diagonal(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn);
bool TieGame(char Board[][7], int8_t Rows, int8_t Columns);
int8_t CheckTehBoard(char GameSymbol, char Board[][7], int8_t Rows, int8_t Columns);
int8_t * CheckTehMoves(char GameSymbol, char Board[][7],int8_t Rows, int8_t Columns);

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.clear();
            }
            while (LikelyInputVariable < 0 || LikelyInputVariable > 1);
            WhoGoesFirst = LikelyInputVariable; //Pick who Goes First
        }
    }
    //Draw Board, Initialize With "-" Simple Board, But a Board None the Less.
    for (int8_t x = 0; x < 6; x++) { for (int8_t y = 0; y < 7; y++) { Board[x][y] = '-'; }}
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
void Creation(ostream & OutPut, char b[][7], int8_t Rectangles, int8_t Colors)
{
    OutPut << endl;
    for (int8_t i = 1; i <= Colors; i++) //Display Column Numbers
        OutPut<<(int) i<<" "; //Display as Integers
    OutPut<<"\n"<<endl;
    for (int8_t x = Rectangles-1; x >= 0; x--)  //Output Game Board
    {
        for (int8_t y = 0; y < Colors; y++)
        {
            if (b[x][y] == 0)
                OutPut << "  ";
            else
                OutPut << b[x][y] << " ";
        }
        OutPut << endl;
    }
    OutPut << endl << endl;
}

//Function that handles the human move
int8_t Human(ostream & OutPut, bool Steel, char Board[][7], int8_t Rows, int8_t Columns)
{
    int AK47; //Col
    int8_t MP40 = 0; //R 4 Row
    char GameSymbol;
    if(Steel == 0)
        GameSymbol = 'X';
    else
        GameSymbol = 'O';
    cout << "What Column would " << (Steel + 1) << " like to play" << endl;
    do
    {
        cout << "Press '0' to quit, or Select Columns '1-7'" << endl;
        cin >> AK47;
    }while(AK47 < 0 || AK47 > 7);
    if(AK47 == 0)
        return -1;
    AK47 -= 1;
    //If a column has already been filled, select again
    if(Board[MP40][AK47] != '-')
    {
        cout << "\nThat Column has already been Filled.\n" << endl;
        return Human(OutPut, Steel, Board, Rows, Columns);
    }
    //Loop Until there is an open space in the board
    while(Board[MP40][AK47] != '-' && MP40<Rows)
        MP40++;
    Board[MP40][AK47] = GameSymbol;
    cout<<"\nPlayer "<<(Steel + 1)<<" plays in column "<<(AK47 + 1)<<endl; //Display Play Message
    OutPut<<"Player "<<(Steel + 1)<<" plays in column "<<(AK47 + 1)<<endl; //Outfile Play Message
    //Check for a winning condition..
    if(Vertical(Board, Rows, Columns, MP40, AK47) || Horizontal(Board, Rows, Columns, MP40, AK47) || Diagonal(Board, Rows, Columns, MP40, AK47))
        return 1;
    if(TieGame(Board, Rows, Columns))
        return 2;
    return 0;
}

//Function that handles the Computer Move
int8_t Computer(ostream & OutPut, int8_t Difficulty, bool FullMetal, char Board[][7], int8_t Rows, int8_t Columns) //This Function Handles the Dumb Computer Move
{
    int8_t AK47 = -1; //cols
    int8_t MP40 = 0; //rows
    int8_t * M16; //Holding computer loss
    char GameSymbol;
    if(FullMetal == 0)
        GameSymbol = 'X';
    else
        GameSymbol = 'O';
    M16 = CheckTehMoves(GameSymbol, Board, Rows, Columns);
    //Basically means as long as the User chooses a Valid Difficulty, And then Determines the Difficulty
    if(Difficulty > 1)
    {
        if(Difficulty == 3 && Board[0][3] == '-')//Highest Difficulty
            AK47 = 3;
        if(AK47 == -1)
            AK47 = CheckTehBoard(GameSymbol, Board, Rows, Columns);
        if(AK47 == -1)
        {
            char TemporaryShit = 'X';
            if(FullMetal == 0)
                TemporaryShit = 'O';
            AK47 = CheckTehBoard(TemporaryShit, Board, Rows, Columns);
        }
        if(AK47 == -1 && Difficulty == 3)
        {
            M16 = CheckTehMoves(GameSymbol, Board, Rows, Columns);
            do
                AK47 = rand()%7;
            while(Board[Rows-1][AK47] != '-' || M16[AK47] != 0);
        }
    }
    for(int i = 0; i < Columns; i++)
        cout << (int)M16[i] << " ";
    cout << endl;
    if(AK47 == 1)
    {
        do
            AK47 = rand()%7;
        while(Board[Rows-1][AK47] != '-');
    }
    while(Board[MP40][AK47] != '-' && MP40 < Rows)
        MP40++;
    Board[MP40][AK47] = GameSymbol; //PLAY PIECE
    cout<<"\nComputer Player "<<(FullMetal+1)<<" plays in column "<<(AK47+1)<<endl; //Display Play Message
    OutPut<<"Computer Player "<<(FullMetal+1)<<" plays in column "<<(AK47+1)<<endl; //Outfile Play Message
    if(Vertical(Board, Rows, Columns, MP40, AK47) || Horizontal(Board, Rows, Columns, MP40, AK47) || Diagonal(Board, Rows, Columns, MP40, AK47))
        return 1;
    if(TieGame(Board, Rows, Columns))
        return 2;
    return 0;
}

//Function that handles a Vertical Win
bool Vertical(char Board[][7], int8_t M249, int8_t Count, int8_t MoveRow, int8_t MoveColumn)
{
    Count = 1; //Hold Count of Consecutive Pieces Vertically
    M249; //To Traverse Array to Check Pieces

    if (MoveRow>=3) //No Point in Checking if not High Enough
    {
        M249 = MoveRow+1; //Intialize Traverse Variable
        while (Board[MoveRow][MoveColumn] == Board[M249][MoveColumn] && M249>=0 && Count<5) //Loop Till Not Matching or Enough Pieces
        {
            Count++; //Increment Count
            M249--; //Check Row Below
        }
        if (Count>=4) //If Enough Consecutive Pieces
            return true;
    }
    return false; //Default, Return False
}
//Function that handles a Horizontal Win
bool Horizontal(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn)
{
    int8_t Count = 1; //Keep Count of Consecutive Pieces
    int8_t Check = MoveColumn-1; //To Traverse Array to Check Pieces
    while (Board[MoveRow][MoveColumn] == Board[MoveRow][Check] && Check>=0 && Count<5) //Count Consecutive Pieces to the Left Till Not Matching or Enough Pieces
    {
        Count++; //Increment Count
        Check--; //Check Column Before
    }
    Check = MoveColumn + 1; //Reinitialize c
    while (Board[MoveRow][MoveColumn] == Board[MoveRow][Check] && Check<Columns && Count<5) //Count Consecutive Pieces to the Right Till Not Matching or Enough Pieces
    {
        Count++; //Increment Count
        Check++; //Check Column After
    }
    if (Count>=4) //If Enough Consecutive Pieces
        return true;
    return false; //Default Return False
}
//Function that handles a Diagonal Win
bool Diagonal(char Board[][7], int8_t Rows, int8_t Columns, int8_t MoveRow, int8_t MoveColumn)
{
    int8_t Count = 1; //Keep Count of Consecutive Pieces
    int8_t MP40 = MoveRow-1; //To Traverse Rows to Check Pieces
    int8_t AK47 = MoveColumn-1; //To Traverse Columns to Check Pieces
    while (Board[MoveRow][MoveColumn] == Board[MP40][AK47] && MP40>=0 && AK47>=0 && Count<5) //Count Consecutive Pieces to the Down-Left
    {
        Count++; //Increment Count
        MP40--; //Check Row Below
        AK47--; //Check Column Before
    }
    MP40 = MoveRow+1; //Reinitialize to Row Above
    AK47 = MoveColumn+1; //Reinitialize to Column After
    while (Board[MoveRow][MoveColumn] == Board[MP40][AK47] && MP40<Rows && AK47<Columns && Count<5) //Count Consecutive Pieces to the Up-Right
    {
        Count++; //Increment Count
        MP40++; //Check Row Below
        AK47++; //Check Column Before
    }
    if (Count>=4) //If Enough Consecutive Pieces
        return true;
    Count = 1; //Reset Count
    MP40 = MoveRow+1; //Reinitialize to Row Above
    AK47 = MoveColumn-1; //Reinitialize to Column Before
    while (Board[MoveRow][MoveColumn] == Board[MP40][AK47] && MP40<Rows && AK47>=0 && Count<5) //Count Consecutive Pieces to the Up-Left
    {
        Count++; //Increment Count
        MP40++; //Check Row Below
        AK47--; //Check Column Before
    }
    MP40 = MoveRow-1; //Reinitialize to Row Below
    AK47 = MoveColumn+1; //Reinitialize to Column After
    while (Board[MoveRow][MoveColumn] == Board[MP40][AK47] && MP40>=0 && AK47<Columns && Count<5) //Count Consecutive Pieces to the Down-Right
    {
        Count++; //Increment Count
        MP40--; //Check Row Below
        AK47++; //Check Column Before
    }
    if (Count>=4) //If Enough Consecutive Pieces
        return true;
    return 0;
}
//Function that hadles a TieGame
bool TieGame(char Board[][7], int8_t Rows, int8_t Columns)
{
    int8_t i = 0; //To Traverse Top Row
    while (Board[Rows-1][i] != '-') //Traverse Top Row
        i++;
    if (i>=Columns) //If Filled Row, Draw Game
        return true;
    return false; //If Not, Return False
}
//Function that Checks Teh Board for a win or a loss
int8_t CheckTehBoard(char GameSymbol, char Board[][7], int8_t Rows, int8_t Columns)
{
    int8_t MP40; //Playing Row
    int8_t AK47 = 0; //Playing Column

    for (AK47; AK47<Columns; AK47++) //Check Each Column
    {
        if (Board[Rows-1][AK47] !='-') //Column is Filled, No Point in Checking
            continue;
        MP40 = 0; //Initialize Row
        while (Board[MP40][AK47] != '-' && MP40<Rows) //Loop Till Open Space in Column Found
            MP40++;
        Board[MP40][AK47] = GameSymbol; //Place Piece
        if(Vertical(Board, Rows, Columns, MP40, AK47) || Horizontal(Board, Rows, Columns, MP40, AK47) || Diagonal(Board, Rows, Columns, MP40, AK47))
        {
            Board[MP40][AK47] = '-'; //Empty Spot
            return AK47; //Return Column Number
        }
        Board[MP40][AK47] = '-'; //Empty Spot
    }
    return -1; //Return -1 on Default
}
//Function that Checks Teh Moves to allow a Human to win
int8_t * CheckTehMoves(char GameSymbol, char Board[][7], int8_t Rows, int8_t Columns)
{
    ///*static*/ bool moves[columns]; //Keep Track of Columns, Results in Size of moves "Not Being Constant"
    static int8_t moves[7]; //Keep Track of Columns
    char tmp = 'X'; //Human Player Symbol
    bool zero = false; //See if moves Contains A Zero, Initialize to False
    int8_t r; //Playing Row
    int8_t c = 0; //Playing Column
    fill_n(moves, 7, 0); //Reset moves
    for (c; c<Columns; c++) //Check Each Column
    {
        if (Board[Rows-2][c] !='-') //Column Has Only Top Spot or Filled, No Point in Checking
        {
            if (Board[Rows-1][c] !='-') //If Column Filled
                moves[c] = 1; //Still Mark as Not Playable
            continue; //Goto Next Interation of for Loop
        }
        r = 0; //Initialize Row
        while (Board[r][c] != '-' && r<Rows-1) //Loop Till Open Space in Column Found
            r++;
        Board[r][c] = GameSymbol; //Place Piece
        Board[++r][c] = GameSymbol; //Inrement r, Place Piece in Row Above
        if(Horizontal(Board, Rows, Columns, r, c) || Diagonal(Board, Rows, Columns, r, c))
            moves[c] = 2; //Mark in Array As Desired Opponent Move (Hold of if Possible)
        if(GameSymbol=='X') //If Computer was Player 1, Switch Symbol
            tmp = 'O';
        Board[r][c] = tmp; //Place Opposite Piece
        if(Horizontal(Board, Rows, Columns, r, c) || Diagonal(Board, Rows, Columns, r, c))
            moves[c] = 1; //Mark in Array
        Board[r][c] = '-'; //Replace Piece
        Board[r-1][c] = '-'; //Replace Piece Under
    }
    for (c=0; c<Columns; c++)
    {
        if (moves[c]==0)
        {
            zero = true;
            break;
        }
    }
    if (zero) //If No Desirable Moves
    {
        for (c=0; c<Columns; c++) //Loop Through Moves
        {
            if (moves[c]==2) //Replace First Located Preferred Opponent Move With Zero
            {
                moves[c] = 0;
                zero = true;
                break;
            }
        }
    }
    if (zero) //If Any Possible Move Results in Human Win (Moves Had All 1s)
        fill_n(moves, 7, 0); //Reset moves, Doesn't Matter
    for (int i=0; i<Columns; i++)
    cout<<moves[i]<<" ";
    cout<<endl;
    return moves;
}
/*
 * /Users/Alex/CLionProjects/ConnectFur/cmake-build-debug/ConnectFur
Welcome to the not so simple game of connect fur.
How many players will be playing today??
Please Enter an Integer Value Between 0 and 2.
0 is CvC. 1 is PvC. 2 is PvP
0

Please Select The Difficulty of the Computer.
Press: 1 Fur Easy. 2 Fur Medium. 3 Fur Hard xD
3

[&&] Woot Woot! Game Start! [%%]

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -


             
0 0 0 0 0 0 0

Computer Player 1 plays in column 4

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - X - - -


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 5

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - X O - -


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 7

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - X O - X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 6

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 3

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 7

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 6

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - - - X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 4

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - - -
- - - O - X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 6

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - X -
- - - O - X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 3

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - - - X -
- - O O - X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 4

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - X - X -
- - O O - X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 5

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - X - X -
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 7

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - X - X X
- - O O O X O
- - X X O O X


             
0 0 0 0 0 0 0

Computer Player 2 plays in column 5

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - -
- - - X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 7

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - X
- - - X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 3

1 2 3 4 5 6 7

- - - - - - -
- - - - - - -
- - - - - - X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 7

1 2 3 4 5 6 7

- - - - - - -
- - - - - - X
- - - - - - X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 5

1 2 3 4 5 6 7

- - - - - - -
- - - - - - X
- - - - O - X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 5

1 2 3 4 5 6 7

- - - - - - -
- - - - X - X
- - - - O - X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 7

1 2 3 4 5 6 7

- - - - - - O
- - - - X - X
- - - - O - X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 6

1 2 3 4 5 6 7

- - - - - - O
- - - - X - X
- - - - O X X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 5

1 2 3 4 5 6 7

- - - - O - O
- - - - X - X
- - - - O X X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 1 plays in column 6

1 2 3 4 5 6 7

- - - - O - O
- - - - X X X
- - - - O X X
- - O X O X X
- - O O O X O
- - X X O O X


             
             
0 0 0 0 0 0 0

Computer Player 2 plays in column 4

1 2 3 4 5 6 7

- - - - O - O
- - - - X X X
- - - O O X X
- - O X O X X
- - O O O X O
- - X X O O X


             
0 0 0 0 0 0 0

Computer Player 1 plays in column 4

1 2 3 4 5 6 7

- - - - O - O
- - - X X X X
- - - O O X X
- - O X O X X
- - O O O X O
- - X X O O X



Player 1 Won!!!!

 */