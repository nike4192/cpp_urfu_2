#include "ChessMoves.h"

void ChessMoves::push_back(ChessMove chessMove)
{
	moves.push_back(chessMove);
}

void ChessMoves::pop_back()
{
	moves.pop_back();
}

ChessMove* ChessMoves::lastMoveTo(int x, int y)
{
	int movesCount = moves.size();

	for (int i = movesCount - 1; i >= 0; i--)
	{
		ChessMove m = moves[i];
		if (m.x == x && m.y == y)
			return &m;
	}
	
	return nullptr;
}