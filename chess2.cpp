#include "pieces.h"

void printBoard(char board[10][10]);
void printMenu(char& userChoice);
bool spaceFree(int x, int y, char board[10][10]);

int main() {

    // Array for storing state of chess board
    char chessBoard[10][10];

    // Creating a blank chess board in array
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            chessBoard[i][j] = ' ';
        }
    }

    // Creation of all pieces using classes
    Pawn p1;
    Rook r1;
    Knight n1;
    King k1;

    // Piece Location Initialization in Array
    chessBoard[p1.getX()][p1.getY()] = 'P';
    chessBoard[r1.getX()][r1.getY()] = 'R';
    chessBoard[n1.getX()][n1.getY()] = 'N';
    chessBoard[k1.getX()][k1.getY()] = 'K';

    // User choice variable
    char userChoice = ' ';

    // Variables for storing users x and y choice
    int userX = 0, userY = 0;

    // Variable for checking if space is taken
    bool space = false;

    // Varaibles that temporarily store coordinates for swapping purposes
    int tempX = 0, tempY = 0;

    printBoard(chessBoard);  // Print initial board state

    do {

        printMenu(userChoice);  // Print menu choices and take in user's choice

        userChoice = toupper(userChoice);  // Force uppercase on user's choice

        switch(userChoice) {  // Check user's menu choice
            case 'P':  // Pawn choice
                cout << "PAWN MOVE: input a valid set of x and y coordinates separated with a space\n";
                cout << "> ";
                cin >> userX >> userY;  // Take in new coordinates

                space = spaceFree(userX, userY, chessBoard);  // Send coordinates to function for validity checking

                if(space) {  // If space is not taken
                    tempX = p1.getX();  // Store previous coordinates in temp variables
                    tempY = p1.getY();

                    p1.Move(userX, userY);  // Call move

                    if(p1.getX() == userX && p1.getY() == userY) {  // If move is successful
                        chessBoard[p1.getX()][p1.getY()] = 'P';  // Update array
                        chessBoard[tempX][tempY] = ' ';
                    }

                    printBoard(chessBoard);  // Print updated board

                    tempX = 0;  // Reset temp variables
                    tempY = 0;
                }

                userX = 0;  // Reset user's coordinate variables
                userY = 0;
                space = false;  // Reset space to taken (default)

                break;
            case 'R':  // Rook choice
                cout << "ROOK MOVE: input a valid set of x and y coordinates separated with a space\n";
                cout << "> ";
                cin >> userX >> userY;  // Take in new coordinates

                space = spaceFree(userX, userY, chessBoard);  // Check if space is valid on board

                if(space) {  // If valid
                    tempX = r1.getX();  // Store current position in temp variables
                    tempY = r1.getY();

                    r1.Move(userX, userY);  // Call move

                    if(r1.getX() == userX && r1.getY() == userY) {  // If move was successful
                        chessBoard[r1.getX()][r1.getY()] = 'R';  // Update array
                        chessBoard[tempX][tempY] = ' ';
                    }

                    printBoard(chessBoard);  // Print updated board

                    tempX = 0;  // Reset temp variables
                    tempY = 0;
                }

                userX = 0;  // Reset user coordinates
                userY = 0;
                space = false;  // Reset space to taken (default)

                break;
            case 'N':  // Knight choice
                cout << "KNIGHT MOVE: input a valid set of x and y coordinates separated with a space\n";
                cout << "> ";
                cin >> userX >> userY;  // Take in user's coordinates

              space = spaceFree(userX, userY, chessBoard);  // Check if coordinates are valid

                if(space) {  // If coordinates are valid
                    tempX = n1.getX();  // Store current coordinates in temp variables
                    tempY = n1.getY();

                    n1.Move(userX, userY);  // Call move

                    if(n1.getX() == userX && n1.getY() == userY) {  // If move was successful
                        chessBoard[n1.getX()][n1.getY()] = 'N';  // Update array
                        chessBoard[tempX][tempY] = ' ';
                    }

                    printBoard(chessBoard);  // Print updated board

                    tempX = 0;  // Reset temp variables
                    tempY = 0;
                }

                userX = 0;  // Reset user coordinates
                userY = 0;
                space = false;  // Reset space to taken (default)

                break;
            case 'K':  // King choice
                cout << "KING MOVE: input a valid set of x and y coordinates separated with a space\n";
                cout << "> ";
                cin >> userX >> userY;  // Take in user's coordinates

                space = spaceFree(userX, userY, chessBoard);  // Check if coordinates are valid

                if(space) {  // If coordinates are valid
                    tempX = k1.getX();  // Store current coordinates in temp variables
                    tempY = k1.getY();

                    k1.Move(userX, userY);  // Call move function

                    if(k1.getX() == userX && k1.getY() == userY) {  // If move was successful
                        chessBoard[k1.getX()][k1.getY()] = 'K';  // Update array
                        chessBoard[tempX][tempY] = ' ';
                    }

                    printBoard(chessBoard);  // Print updated board

                    tempX = 0;  // Reset temporary variables
                    tempY = 0;
                }

                userX = 0;  // Reset user coordinates
                userY = 0;
                space = false;  // Reset space to taken (default)

                break;
            case 'X':  // User selects exit
                cout << "Thank you for using 10x10 CHESS!\n";
                printBoard(chessBoard);  // Print the final state of the board
                break;
            default:  // Invalid menu choice
                cout << "Sorry, that was not a valid menu choice\n";
                cout << "Please read the menu options carefully, and try again...\n";
                break;
        }

    }while(userChoice != 'X');  // Break loop if user selects exit

    return 0;
}


// Function for printing the current state of the chess board
void printBoard(char board[10][10]) {

cout << "┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐" << '\n';
for(int i = 9; i >= 0; i--) {
    for(int j = 0; j < 10; j++) {
        cout << "│ " << board[j][i] << ' ';
    }
    if(i > 0)
        cout << "│" << '\n' << "├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤\n";
    else
        cout << "│";

}
cout << "\n└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘\n";

}

// Display menu
void printMenu(char& userChoice) {

    cout << "\n10x10 Chess Menu Options\n";
    cout << "------------------------\n";
    cout << "Type any of the following characters:\n";
    cout << "P - Move Pawn\n";
    cout << "R - Move Rook\n";
    cout << "N - Move Knight\n";
    cout << "K - Move King\n";
    cout << "X - Exit Game\n\n";
    cout << "> ";
    cin >> userChoice;

}

// Checking if space is free function
bool spaceFree(int x, int y, char board[10][10]) {

    if(board[x][y] == ' ')  // If space is unoccupied
        return true;
    else if(board[x][y] == 'P' || board[x][y] == 'R' || board[x][y] == 'N' || board[x][y] == 'K') {  // If space has any pieces on it
        cout << "Spot occupied or invalid move detected. Try again...\n";
        return false;
    }
    else {  // If coordinates are negative or out of bounds of array
        cout << "Error with chosen coordinates. Make sure you type a value between 0 and 9 for both x and y. Try again...\n";
        return false;
    }
}