// make a tic tac toe game !
// create 3x3 board and manipulate based on user input
// make func to display it, track movement, check winner and tie
// style guide compliant (checked?)

#include <iostream>
using namespace std;

//const declared

const int SIZE = 3; // standard size of board

// func prototypes

void showBoard(char board[SIZE][SIZE]); // show board
bool makeMove(char board[SIZE][SIZE], int row, int col, char player); // update board movement
bool checkWin(char board[SIZE][SIZE], char player); // check if board has winner

// func to display the current board to user

void showBoard(char board[SIZE][SIZE]) 
{
    cout << "\n";
    
    // loop thro board and print current state
    
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// func to make the move

bool makeMove(char board[SIZE][SIZE], int row, int col, char player) 
{
    
    // verify row&column is within range and cell is empty
    
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '*') 
    {
        board[row][col] = player; //place x/o in corresponding spot
        return true;
    }
    return false; // invalid move
}

// func to check if someone won

bool checkWin(char board[SIZE][SIZE], char player) 
{
    // check horizontal/vertical wins

    for (int i = 0; i < SIZE; i++) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }
    
    // check diagonal wins
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true; //detected
    }
    
    return false; //n/a
}

int main() 
{
    char board[SIZE][SIZE];
    
    // create board with *
    
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            board[i][j] = '*';
        }
    }
    
    // initialize vars

    char currentPlayer = 'X';
    int row;
    int col;
    int moves = 0;
    
    // while movement is possible ask and execute
    
    while (true) 
    {

        // show the board and ask for point

        showBoard(board); // show board
        if (currentPlayer == 'X')
        {
            cout<< "Player 1 (X) ~ enter in a valid row and column from 1-3: ";
        }
        else
        {
            cout<< "Player 2 (O) ~ enter in a valid row and column from 1-3: ";
        }

        // gather user input

        cin >> row >> col;
        
        // Adjust for [0] indexing

        row--;
        col--;
        
        // make move and check status

        if (makeMove(board, row, col, currentPlayer)) 
        {
            moves++; //update
            
            if (checkWin(board, currentPlayer))  // if one wins
            {
                showBoard(board);
                if (currentPlayer =='X')
                {
                    cout<< "Player 1 (X) WINS!"<< endl;
                }
                else
                {
                    cout << "Player 2 (O) WINS!"<< endl;
                }
                break;
            } 
            else if (moves == 9) //board is full, tie
            { 
                showBoard(board);
                cout << "Game Over. it's a TIE." << endl;
                break;
            }
            
            // after move- switch
            
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer ='X';
            }
        } 
        else 
        {
            cout << "x_x Invalid move x_x" << endl;
            cout << "Enter valid, empty spot : row col(1-3)" << endl; //false 
        }
    }
    return 0;
}

// end of program
