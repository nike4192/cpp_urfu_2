#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include "ChessPiece.h";

enum CHESS_PLAYER { WHITE, BLACK };

class ChessMove
{
	friend class ChessMoves;

private:
	CHESS_PLAYER player;
	ChessPiece piece;
	int x, y;

public:
	ChessMove(CHESS_PLAYER _player, ChessPiece _piece, int _x, int _y);

	CHESS_PLAYER getPlayer();

	int getX();
	int getY();
};

#endif