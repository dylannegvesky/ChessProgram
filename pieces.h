#include <iostream>

using namespace std;

// PAWN
class Pawn{

public:
	// Setter for pawn position
	void Move(int x, int y);
	
	// Getters for x and y pos
	int getX();
	int getY();

	// Constructor for pawn
	Pawn();

private:
	// Pawn positional coordinates
	int x, y;
	
	// Boolean variable to check if it is the pawn's first move
	bool firstMove;	

	// Pawn move validity checker
	bool pawnValidMv(int x, int y);
	
};

// ROOK
class Rook{

public: 
	// Setter for rook position
	void Move(int x, int y);
	
	// Getter for x and y pos
	int getX();
	int getY();

	// Constructor for rook
	Rook();

private:
	// Rook positional coordinates
	int x, y;

	// Rook move validity checker
	bool rookValidMv(int x, int y);

};

// KNIGHT
class Knight{

public: 
	// Setter for knight position
	void Move(int x, int y);

	// Getter for x and y pos
	int getX();
	int getY();

	// Constructor for knight
	Knight();

private:
	// Knight positional coordinates
	int x, y;

	// Knight move validity checker
	bool knightValidMv(int x, int y);

};
	
// KING
class King{

public:
	// Setter for king position
	void Move(int x, int y);

	// Getter for x and y pos
	int getX();
	int getY();

	// Constructor for king 
	King();

private:
	// King positional coordinates
	int x, y;

	// King move validity checker
	bool kingValidMv(int x, int y);

};
