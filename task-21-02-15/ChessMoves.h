#ifndef CHESSMOVES_H
#define CHESSMOVES_H

#include "ChessMove.h"
#include <vector>

/*
Вектор, потому что
1) Сохраняется последовательность
2) Можно просматривать все элементы
3) Можно добавлять одинаковые (по значениям) элементы
4) Не нужна ассоциативность для ходов
*/

class ChessMoves
{
private:

public:
	std::vector<ChessMove> moves;

	void push_back(ChessMove chessMove);
	void pop_back();
	ChessMove* lastMoveTo(int x, int y);

};

#endif