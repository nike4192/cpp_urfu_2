#include "ChessMove.h"
#include "ChessPiece.h"

ChessMove::ChessMove(CHESS_PLAYER _player, ChessPiece _piece, int _x, int _y): player(_player), piece(_piece), x(_x), y(_y) {}

CHESS_PLAYER ChessMove::getPlayer() { return player; }
int ChessMove::getX() { return x; }
int ChessMove::getY() { return y; }