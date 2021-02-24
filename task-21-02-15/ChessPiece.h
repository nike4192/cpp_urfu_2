#ifndef CHESSPIECE_H
#define CHESSPIECE_H

enum CHESS_PIECE { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

class ChessPiece
{
	friend class ChessMove;

private:
	CHESS_PIECE type;

public:
	ChessPiece(CHESS_PIECE _type);
};

#endif