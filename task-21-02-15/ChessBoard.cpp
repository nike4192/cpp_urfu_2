#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for (int x = 0; x < boardSizeX; x++)
		for (int y = 0; y < boardSizeY; y++)
			map[x][y] = nullptr;
}

void ChessBoard::setPieceAt(int x, int y, ChessPiece* chessPiece)
{
	map[x][y] = chessPiece;
}

ChessPiece* ChessBoard::popPieceAt(int x, int y)
{
	ChessPiece* cptr = map[x][y];

	map[x][y] = nullptr;

	return cptr;
}

ChessPiece* ChessBoard::getPieceAt(int x, int y) const
{
	return map[x][y];
}
