#ifndef CHESSMOVES_H
#define CHESSMOVES_H

#include "ChessMove.h"
#include <vector>

/*
������, ������ ���
1) ����������� ������������������
2) ����� ������������� ��� ��������
3) ����� ��������� ���������� (�� ���������) ��������
4) �� ����� ��������������� ��� �����
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