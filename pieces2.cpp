#include "pieces.h"

// Generally defined function for checking boundary of board with user's move
bool inBounds(int x, int y) {

	if(x <= 9 && x >= 0 && y <= 9 && y >= 0)  // If user's coordinates are within bounds
		return true;
	else {
		return false;
	}

}

// PAWN

// Move function
void Pawn::Move(int x, int y) {
	
	bool valid = pawnValidMv(x, y);  // Call the valid move function and store result

	if(valid)  // If move is valid
		this->y = y;  // Update pawn y position
	else
		cout << "That move is invalid, try again.\n";
	
}

// Valid move checking function
bool Pawn::pawnValidMv(int x, int y) {

	if(firstMove == true) {  // Check if it is pawn's first move
		if(y <= this->y + 2 && x == this->x && y > this->y && inBounds(x, y)) {  // If the pawn's move is legal and in bounds
			this->firstMove = false;  // Update first move to false
			return true;  // Return true
		}
		else
			return false;  // Invalid move: return false
	}
	else if(firstMove == false) {  // Check if pawn's first move
		if(y <= this->y + 1 && x == this->x && y > this->y && inBounds(x, y))  // If the pawn's move is legal and in bounds
			return true;  // Return true
		else
			return false;  // Invalid move: return false
	}
	else
		return false;  // Error catching: return false
}

// Getter for pawn x pos
int Pawn::getX() {
	return x;
}

// Getter for pawn y pos
int Pawn::getY() {
	return y;
}

// Constructor for pawn
Pawn::Pawn(){
	x = 3;
	y = 0;
	firstMove = true;
}

// ROOK

// Move function
void Rook::Move(int x, int y) {

	bool valid = rookValidMv(x, y);  // Call valid move function and store result

	if(valid) {  // If move is valid
		this->x = x;  // Update coordinates
		this->y = y;
	}
	else  // Invalid move
		cout << "That move is invalid, try again.\n";

}

// Valid move checking function
bool Rook::rookValidMv(int x, int y)
{
	if(this->x != x && this->y != y) {  // If user attempts to move diagnally (invalid)
		cout << "That move is invalid, try again.\n";
		return false;
	}
	else if(this->x == x && this->y != y && inBounds(x, y))  // If user moves along the y axis appropriately and in bounds (valid)
		return true;
	else if(this->x != x && this->y == y && inBounds(x, y))  // If user moves along the x axis appropriately and in bounds (valid)
		return true;
	else
		return false;  // Error catching: return false
}

// Getter for rook x pos
int Rook::getX() {
	return x;
}

// Getter for rook y pos
int Rook::getY() {
	return y;
}

// Constructor for rook
Rook::Rook(){
	x = 4;
	y = 0;
}

// KNIGHT

// Move function
void Knight::Move(int x, int y) {
	
	bool valid = knightValidMv(x, y);  // Call valid move function and store result

	if(valid) {  // If move is valid
		this->x = x;  // Update coordinates
		this->y = y;
	}
	else  // Invalid move
		cout << "That move is invalid, try again.\n";

}

// Valid move checking function
bool Knight::knightValidMv(int x, int y)
{
	if(x == this->x + 2 && (y == this->y + 1 || y == this->y - 1) && inBounds(x, y))  // If knight moves 2 right, up 1 or down 1, and in bounds (valid)
		return true;
	else if(x == this->x - 2 && (y == this->y + 1 || y == this->y - 1) && inBounds(x, y)) // If knight moves 2 left, up 1 or down 1, and in bounds (valid)
		return true;
	else if(y == this->y + 2 && (x == this->x + 1 || x == this->x - 1) && inBounds(x, y)) // If knight moves 2 up, right 1 or left 1, and in bounds (valid)
		return true;
	else if(y == this->y - 2 && (x == this->x + 1 || x == this->x - 1) && inBounds(x, y)) // If knight moves 2 down, right 1 or left 1, and in bounds (valid)
		return true;
	else  // Invalid move
		return false;
}

// Getter for knight x pos
int Knight::getX() {
	return x;
}

// Getter for knight y pos
int Knight::getY() {
	return y;
}

// Constructor for knight
Knight::Knight(){
	x = 5;
	y = 0;
}

// KING

// Move function
void King::Move(int x, int y) {
	
	bool valid = kingValidMv(x, y);  // Call valid move function and store result

	if(valid) {  // If move is valid
		this->x = x;  // Update coordinates
		this->y = y;
	}
	else  // Invalid move
		cout << "That move is invalid, try again.\n";
}

// Valid move checking function
bool King::kingValidMv(int x, int y)
{
	if((x == this->x + 1 || x == this->x - 1) && (y == this->y + 1 || y == this->y - 1) && inBounds(x, y))  // If king moves diagnally 1 square (valid)
		return true;
	else if((x == this->x + 1 || x == this->x - 1) && y == this->y && inBounds(x, y))  // If king moves left or right 1 square (valid)
		return true;
	else if((y == this->y + 1 || y == this->y - 1) && x == this->x && inBounds(x, y))  // If king moves up or down 1 square (valid)
		return true;
	else  // Invalid move
		return false;
}


// Getter for king x pos
int King::getX() {
	return x;
}

// Getter for king y pos
int King::getY() {
	return y;
}


// Constructor for king
King::King(){
	x = 6;
	y = 0;
}




