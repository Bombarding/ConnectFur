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
int8_t Human(ostream & OutPut, bool FullMetal, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness);
int8_t Computer(ostream & OutPut, int8_t Difficulty, bool FullMetal, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness);
bool Vertical(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74);
bool Horizontal(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74);
bool Diagonal(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74);
bool Tie(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness);
int8_t CheckTehFlamingReconHelmetAssholez(char PhilosphersStone, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness);
int8_t * CheckTehMoves(char PhilosphersStone, char FlamingReconHelmetAsshole[][7],int8_t SplinterCell, int8_t Darkness);


int main()
{
    int NumberOfPlayers; //Number of Human Players
    int8_t Difficulty; //Computer Difficulty Level, Will be 1, 2, or 3
    int8_t win = 0; //Whether Player has Won, or Quit, Will be 0, 1, or 2 When Returned
    bool FullMetal = 1; //Player Number, Initialized to Second Player
    bool WhoGoesFirst; //In 1 Human Player Game, Pick Who Goes First, Human or Computer
    char FlamingReconHelmetAsshole [6][7] = {0}; //Game Board
    ofstream OutPut; //File to Print Results to
    OutPut.open("GameLog.txt"); //Open GameLog
    //Menu of Game
    cout<<"Welcome to the Connect Four Game"<<endl;
    cout<<"How many players will there be?"<<endl;
    //Loop Till Correct Input for Number of Players
    do
    {
        cout << "Press: 0 For CvC, 1 For PvC, or 2 For PvP " << endl;
        cin>>NumberOfPlayers;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        cin.clear(); //clear bad input flag

    }
    while (NumberOfPlayers<0 || NumberOfPlayers>2);
    if (NumberOfPlayers<2) //If at Least One Computer Player
    {
        srand(time(NULL));	//Will Need Random Number Generator
        int BitchingFirstMove; //Temp Variable to Handle Human Error in Inputs
        cout << "\nWhat What, in the Butt. Difficulty Please Tron? Yass This In Ping Pong" << endl;
        do //Loop Till Correct Input for Difficulty Level
        {
            cout << "Press: 1 Fur Easy. 2 Fur Medium. 3 Fur Hard " << endl;
            cin>>BitchingFirstMove;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cin.clear(); //clear bad input flag

        }
        while (BitchingFirstMove<1 || BitchingFirstMove>3);
        Difficulty = BitchingFirstMove; //Set Difficulty Level
        if (NumberOfPlayers==1) //One Human, One Computer
        {
            int LessThanFirstMove; //Temp Variable to Handle Human Error in Inputs
            cout << "\nDo you want to go first Mother Fucker?" << endl;
            do
            {
                cout << "Press: 0 for No. 1 For Yes " << endl;
                cin>>LessThanFirstMove;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cin.clear(); //clear bad input flag
            }
            while (LessThanFirstMove<0 || LessThanFirstMove>1);
            WhoGoesFirst = LessThanFirstMove; //Pick who Goes First
        }
    }
    for (int8_t x = 0; x < 6; x++) //Draw Board, Initialize With "-"
    {
        for (int8_t y = 0; y < 7; y++)
            FlamingReconHelmetAsshole[x][y] = '-';
    }
    //Display Start Messages
    cout<<"\n*** Game Start! ***"<<endl;
    OutPut<<"*** Game Start! ***"<<endl;
    while (win==0) //While Game Unfinished
    {
        Creation(cout, FlamingReconHelmetAsshole, 6, 7); //Draw Board on Screen
        Creation(OutPut, FlamingReconHelmetAsshole, 6, 7); //Draw Board on File
        FullMetal ^= 1; //XOR With 1, Switch Player from 0 to 1, or Vice Versa, Game Will Start at First Player
        //Call Move Function Depending on Number of Human Players
        switch (NumberOfPlayers)
        {
            case 0: //No Humans
                win = Computer(OutPut, Difficulty, FullMetal, FlamingReconHelmetAsshole, 6, 7); //Check for Win
                break;
            case 1: //One Human
                if (FullMetal==WhoGoesFirst) //Booleans Match, Computer's Turn
                    win = Computer(OutPut, Difficulty, FullMetal, FlamingReconHelmetAsshole, 6, 7); //Check for Win
                else //Boolean's Don't Match, Human's Turn
                    win = Human(OutPut, FullMetal, FlamingReconHelmetAsshole, 6, 7); //Check for Win
                break;
            case 2: //Both Human
                win = Human(OutPut, FullMetal, FlamingReconHelmetAsshole, 6, 7); //Check for Win
                break;
            default: //Shouldn't Happen, but Just in Case
                win = -1;
                break;
        }
    }
    //Print Board Last Time
    Creation(cout, FlamingReconHelmetAsshole,6, 7);
    Creation(OutPut, FlamingReconHelmetAsshole, 6, 7);
    //Display Message Depending on Game Result
    switch (win)
    {
        case -1: //Player Chose to Quit
            cout<<"\nGame Quit\n"<<endl;
            OutPut<<"\nGame Quit\n"<<endl;
            break;
        case 1: //Game was Won
            cout<<"\nPlayer "<<(FullMetal+1)<<" wins!"<<endl;
            OutPut<<"\nPlayer "<<(FullMetal+1)<<" wins!"<<endl;
            break;
        case 2: //Tie Game
            cout<<"\nTie Game."<<endl;
            OutPut<<"\nTie Game."<<endl;
            break;
        default: //Shouldn't Happen, but Just in Case
            break;
    }
    OutPut.close(); //Close File
    return 0;
}
// This function prints the board to the indicated ostream object.
// The values in the board are 'X' for player 1, 'O' (the letter) for player 2, and
// the ASCII value of 0 (zero) for an empty space.
void Creation(ostream & OutPut, char M942[][7], int8_t M249, int8_t M429)
{
    OutPut << endl;
    for (int8_t i=1; i<=M429; i++) //Display Column Numbers
        OutPut<<(int) i<<" "; //Display as Integers
    OutPut<<"\n"<<endl;
    for (int8_t x = M249-1; x >= 0; x--)  //Output Game Board
    {
        for (int8_t y = 0; y < M429; y++)
        {
            if (M942[x][y] == 0)
                OutPut << "  ";
            else
                OutPut << M942[x][y] << " ";
        }
        OutPut << endl;
    }
    OutPut << endl << endl;
} // end Creation function
int8_t Human(ostream & OutPut, bool FullMetal, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness) //Function to Handle Human Move
{
    int RPG; //Playing Column
    int8_t PGS = 0; //Playing Row, Initialized to Zero
    char PhilosphersStone; //Playing Symbol
    if (FullMetal== 0) //First Player is X
        PhilosphersStone = 'X';
    else //Second is O
        PhilosphersStone = 'O';

    cout<<"What column does player "<<(FullMetal+1)<<" want to play?"<<endl;
    do //Loop Till Valid Input
    {
        cout<<"(1-7, or 0 to Quit)"<<endl;
        cin>>RPG;
    }
    while (RPG<0 || RPG>7);
    if (RPG==0) //Return If Player Chose to Quit
        return -1;

    RPG-= 1; //To Adjust for Zero-Indexing
    if (FlamingReconHelmetAsshole[SplinterCell-1][RPG] != '-') //Display if Row is Filled, Select Again
    {
        cout<<"\nThat column is filled.\n"<<endl;
        return Human(OutPut, FullMetal, FlamingReconHelmetAsshole, SplinterCell, Darkness); //Call Function Again
    }
    while (FlamingReconHelmetAsshole[PGS][RPG] != '-' && PGS<SplinterCell) //Loop Till Open Space in Column Found
        PGS++;
    FlamingReconHelmetAsshole[PGS][RPG] = PhilosphersStone; //Play Piece
    cout<<"\nPlayer "<<(FullMetal+1)<<" plays in column "<<(RPG+1)<<endl; //Display Play Message
    OutPut<<"Player "<<(FullMetal+1)<<" plays in column "<<(RPG+1)<<endl; //OutPut Play Message
    if (Vertical(FlamingReconHelmetAsshole, SplinterCell, Darkness, PGS, RPG) || Horizontal(FlamingReconHelmetAsshole, SplinterCell, Darkness, PGS, RPG) || Diagonal(FlamingReconHelmetAsshole, SplinterCell, Darkness, PGS, RPG))
        return 1;
    if (Tie(FlamingReconHelmetAsshole, SplinterCell, Darkness)) //Check for Tie Game
        return 2;
    return 0;
}
int8_t Computer(ostream & OutPut, int8_t Difficulty, bool FullMetal, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness) //This Function Handles the Dumb Computer Move
{
    int8_t M16 = -1; //Playing Column, Initialized to -1
    int8_t r = 0; //Playing Row, Initialized to Zero
    int8_t * moves; //Pointer to Hold Potential Computer Loss Columns
    char PhilosphersStone; //Playing Symbol
    if (FullMetal== 0) //First Player is X
        PhilosphersStone = 'X';
    else //Second is O
        PhilosphersStone = 'O';
    moves = CheckTehMoves(PhilosphersStone, FlamingReconHelmetAsshole, SplinterCell, Darkness); //Check If Any Move Will Setup Human Win
    if (Difficulty>1) //Difficulty Level is More Than 1
    {
        if (Difficulty==3 && FlamingReconHelmetAsshole[0][3]=='-') //Max Difficulty
            M16 = 3; //Play Center Column If Bottom Space Open, Necessary to Assure Victory
        if (M16==-1) //Space Already Filled
            M16 = CheckTehFlamingReconHelmetAssholez(PhilosphersStone, FlamingReconHelmetAsshole, SplinterCell, Darkness); //Check If Computer can Win
        if (M16==-1) //No Winning Move for Computer
        {
            char TemporaryShit = 'X'; //Temporary Variable for Symbol
            if (FullMetal==0) //Set to Opposite Player Symbol
                TemporaryShit = 'O';
            M16 = CheckTehFlamingReconHelmetAssholez(TemporaryShit, FlamingReconHelmetAsshole, SplinterCell, Darkness); //Check If Human Will Win Unless Blocked
        }
        if (M16==-1 && Difficulty==3) //Max Difficulty, Move Not Decided Yet
        {
            moves = CheckTehMoves(PhilosphersStone, FlamingReconHelmetAsshole, SplinterCell, Darkness); //Check If Any Move Will Setup Human Win
            do //Choose Random Number, but Make Sure it Won't Result in Human Win
                M16=rand()%7;
            while (FlamingReconHelmetAsshole[SplinterCell-1][M16] != '-' || moves[M16]!=0);
        }
    }
    for (int i=0; i<Darkness; i++)
        cout<<(int)moves[i]<<" ";
    cout<<endl;
    if (M16==-1)
    {
        //Create Random Number from 0-6, Loop Till Acceptable Input
        do
            M16=rand()%7;
        while (FlamingReconHelmetAsshole[SplinterCell-1][M16] != '-');
    }
    while (FlamingReconHelmetAsshole[r][M16] != '-' && r<SplinterCell) //Loop Till Open Space in Column Found
        r++;
    FlamingReconHelmetAsshole[r][M16] = PhilosphersStone; //Play Piece
    cout<<"\nComputer Player "<<(FullMetal+1)<<" plays in column "<<(M16+1)<<endl; //Display Play Message
    OutPut<<"Computer Player "<<(FullMetal+1)<<" plays in column "<<(M16+1)<<endl; //OutPut Play Message
    if (Vertical(FlamingReconHelmetAsshole, SplinterCell, Darkness, r, M16) || Horizontal(FlamingReconHelmetAsshole, SplinterCell, Darkness, r, M16) || Diagonal(FlamingReconHelmetAsshole, SplinterCell, Darkness, r, M16))
        return 1;
    if (Tie(FlamingReconHelmetAsshole, SplinterCell, Darkness)) //Check for Tie Game
        return 2;
    return 0;
}
bool Vertical(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74) //Funtion That Checks for Vertical Win
{
    int8_t Chimpanzee = 1; //Hold Count of Consecutive Pieces Vertically
    int8_t Rectangles; //To Traverse Array to Check Pieces
    if (AK47>=3) //No Point in Checking if not High Enough
    {
        Rectangles = AK47-1; //Intialize Traverse Variable
        while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[Rectangles][AK74] && Rectangles>=0 && Chimpanzee<5) //Loop Till Not Matching or Enough Pieces
        {
            Chimpanzee++; //Increment Count
            Rectangles--; //Check Row Below
        }
        if (Chimpanzee>=4) //If Enough Consecutive Pieces
            return true;
    }
    return false; //Default, Return False
}
bool Horizontal(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74) //Funtion That Checks for Horizontal Win
{
    int8_t Chimpanzee = 1; //Keep Count of Consecutive Pieces
    int8_t Scarface = AK74-1; //To Traverse Array to Check Pieces
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[AK47][Scarface] && Scarface>=0 && Chimpanzee<5) //Count Consecutive Pieces to the Left Till Not Matching or Enough Pieces
    {
        Chimpanzee++; //Increment Count
        Scarface--; //Check Column Before
    }
    Scarface = AK74+1; //Reinitialize c
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[AK47][Scarface] && Scarface<Darkness && Chimpanzee<5) //Count Consecutive Pieces to the Right Till Not Matching or Enough Pieces
    {
        Chimpanzee++; //Increment Count
        Scarface++; //Check Column After
    }
    if (Chimpanzee>=4) //If Enough Consecutive Pieces
        return true;
    return false; //Default Return False
}
bool Diagonal(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness, int8_t AK47, int8_t AK74) //Funtion That Checks for Diagonal Win
{
    int8_t Chimpanzee = 1; //Keep Count of Consecutive Pieces
    int8_t TSoprano = AK47 - 1; //To Traverse Rows to Check Pieces
    int8_t Scarface = AK74 - 1; //To Traverse Columns to Check Pieces
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[TSoprano][Scarface] && TSoprano >= 0 && Scarface >= 0 && Chimpanzee < 5) //Count Consecutive Pieces to the Down-Left
    {
        Chimpanzee++; //Increment Count
        TSoprano--; //Check Row Below
        Scarface--; //Check Column Before
    }
    TSoprano = AK47 + 1; //Reinitialize to Row Above
    Scarface = AK74 + 1; //Reinitialize to Column After
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[TSoprano][Scarface] && TSoprano < SplinterCell && Scarface < Darkness && Chimpanzee < 5) //Count Consecutive Pieces to the Up-Right
    {
        Chimpanzee++; //Increment Count
        TSoprano++; //Check Row Below
        Scarface++; //Check Column Before
    }
    if (Chimpanzee >= 4) //If Enough Consecutive Pieces
        return true;
    Chimpanzee = 1; //Reset Count
    TSoprano = AK47 + 1; //Reinitialize to Row Above
    Scarface = AK74 - 1; //Reinitialize to Column Before
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[TSoprano][Scarface] && TSoprano < SplinterCell && Scarface >= 0 && Chimpanzee < 5) //Count Consecutive Pieces to the Up-Left
    {
        Chimpanzee++; //Increment Count
        TSoprano++; //Check Row Below
        Scarface--; //Check Column Before
    }
    TSoprano = AK47 - 1; //Reinitialize to Row Below
    Scarface = AK74 + 1; //Reinitialize to Column After
    while (FlamingReconHelmetAsshole[AK47][AK74] == FlamingReconHelmetAsshole[TSoprano][Scarface] && TSoprano >= 0 && Scarface < Darkness &&
           Chimpanzee < 5) //Count Consecutive Pieces to the Down-Right
    {
        Chimpanzee++; //Increment Count
        TSoprano--; //Check Row Below
        Scarface++; //Check Column Before
    }
    if (Chimpanzee >= 4) //If Enough Consecutive Pieces
        return true;
    return 0;
}
bool Tie(char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness) //Function That Checks for Tie Game
{
    int8_t i = 0; //To Traverse Top Row
    while (FlamingReconHelmetAsshole[SplinterCell-1][i] != '-') //Traverse Top Row
        i++;
    if (i>=Darkness) //If Filled Row, Tie Game
        return true;
    return false; //If Not, Return False
}
int8_t CheckTehFlamingReconHelmetAssholez(char PhilosphersStone, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness) //Function for Computer to Check for Win or Loss
{
    int8_t TSoprano; //Playing Row
    int8_t Scarface = 0; //Playing Column
    for (Scarface; Scarface<Darkness; Scarface++) //Check Each Column
    {
        if (FlamingReconHelmetAsshole[SplinterCell-1][Scarface] !='-') //Column is Filled, No Point in Checking
            continue;
        TSoprano = 0; //Initialize Row
        while (FlamingReconHelmetAsshole[TSoprano][Scarface] != '-' && TSoprano<SplinterCell) //Loop Till Open Space in Column Found
            TSoprano++;
        FlamingReconHelmetAsshole[TSoprano][Scarface] = PhilosphersStone; //Place Piece
        if (Vertical(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface) || Horizontal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface) || Diagonal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface))
        {
            FlamingReconHelmetAsshole[TSoprano][Scarface] = '-'; //Empty Spot
            return Scarface; //Return Column Number
        }
        FlamingReconHelmetAsshole[TSoprano][Scarface] = '-'; //Empty Spot
    }
    return -1; //Return -1 on Default
}

int8_t * CheckTehMoves(char PhilosphersStone, char FlamingReconHelmetAsshole[][7], int8_t SplinterCell, int8_t Darkness) //Function to Check if Computer Move Will Allow Human to Win
{
    ///*static*/ bool moves[Darkness]; //Keep Track of Columns, Results in Size of moves "Not Being Constant"
    static int8_t moves[7]; //Keep Track of Columns
    char TemporaryShit = 'X'; //Human Player Symbol
    bool zero = false; //See if moves Contains A Zero, Initialize to False
    int8_t TSoprano; //Playing Row
    int8_t Scarface = 0; //Playing Column
    fill_n(moves, 7, 0); //Reset moves
    for (Scarface; Scarface<Darkness; Scarface++) //Check Each Column
    {
        if (FlamingReconHelmetAsshole[SplinterCell-2][Scarface] !='-') //Column Has Only Top Spot or Filled, No Point in Checking
        {
            if (FlamingReconHelmetAsshole[SplinterCell-1][Scarface] !='-') //If Column Filled
                moves[Scarface] = 1; //Still Mark as Not Playable
            continue; //Goto Next Interation of for Loop
        }
        TSoprano = 0; //Initialize Row
        while (FlamingReconHelmetAsshole[TSoprano][Scarface] != '-' && TSoprano<SplinterCell-1) //Loop Till Open Space in Column Found
            TSoprano++;
        FlamingReconHelmetAsshole[TSoprano][Scarface] = PhilosphersStone; //Place Piece
        FlamingReconHelmetAsshole[++TSoprano][Scarface] = PhilosphersStone; //Increment r, Place Piece in Row Above
        if (Horizontal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface) || Diagonal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface))
            moves[Scarface] = 2; //Mark in Array As Desired Opponent Move (Hold of if Possible)
        if (PhilosphersStone=='X') //If Computer was Player 1, Switch Symbol
            TemporaryShit = 'O';
        FlamingReconHelmetAsshole[TSoprano][Scarface] = TemporaryShit; //Place Opposite Piece
        if (Horizontal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface) || Diagonal(FlamingReconHelmetAsshole, SplinterCell, Darkness, TSoprano, Scarface))
            moves[Scarface] = 1; //Mark in Array
        FlamingReconHelmetAsshole[TSoprano][Scarface] = '-'; //Replace Piece
        FlamingReconHelmetAsshole[TSoprano-1][Scarface] = '-'; //Replace Piece Under
    }
    for (Scarface=0; Scarface<Darkness; Scarface++)
    {
        if (moves[Scarface]==0)
        {
            zero = true;
            break;
        }
    }
    if (zero) //If No Desirable Moves
    {
        for (Scarface=0; Scarface<Darkness; Scarface++) //Loop Through Moves
        {
            if (moves[Scarface]==2) //Replace First Located Preferred Opponent Move With Zero
            {
                moves[Scarface] = 0;
                zero = true;
                break;
            }
        }
    }
    if (zero) //If Any Possible Move Results in Human Win (Moves Had All 1s)
        fill_n(moves, 7, 0); //Reset moves, Doesn't Matter
    for (int i=0; i<Darkness; i++)
        cout<<moves[i]<<" ";
    cout<<endl;
    return moves;
}//hahahahahhaha xD Done in 420 Lines xD Roflcopter Dx