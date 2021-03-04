#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <map>

/* 3 Класс для хранения последовательностей ходов в шахматной партии */

/* ~~Выберите подходящий контейнер~~
 *	map, потому что
 *	у каждой ячейки можеть быть максимум одна фигура (ассоциативность)
*/

class ChessPiece {};

class ChessBoard
{
public:

	static const int boardSizeX = 8;
	static const int boardSizeY = 8;

	ChessBoard();

	void setPieceAt(int x, int y, ChessPiece* chessPiece);
	ChessPiece* popPieceAt(int x, int y); // не const потому что заменяет chessPiece на nullptr
	ChessPiece* getPieceAt(int x, int y) const;

private:

	class ChessPiece* map[boardSizeX][boardSizeY];
};

#endif
