#include <iostream>
#include <list>
#include <cmath>

#include "Complex.h" // 1.1
#include "Vector4.h" // 1.2
#include "Vector2.h" // 2
#include "ChessMoves.h" // 3

std::ostream& operator<< (std::ostream& os, const Complex& c) {

	os << "complex(" << c.getReal() << ", " << c.getImag() << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, const Vector4& v) {

	os << "vec4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, const Vector2& v) {

	os << "vec2(" << v.x << ", " << v.y << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, ChessMove& m) {

	CHESS_PLAYER p = m.getPlayer();

	os
		<< "chess_move("
		<< (p == CHESS_PLAYER::WHITE ? "white" : p == CHESS_PLAYER::BLACK ? "black" : "undefined")
		<< ", " << m.getX() << ", " << m.getY()
		<< ")";

	return os;
}

template<typename T>
void print(T ivalue)
{
	std::cout << ivalue << std::endl;
}

int main()
{
	/* 1.1 Complex */

	Complex c1(13, 1);
	Complex c2(7, -6);

	std::cout << "c1: " << c1 << std::endl;
	std::cout << "c2: " << c2 << std::endl;

	std::cout << "c1 + c2: " << c1 + c2 << std::endl;
	std::cout << "c1 - c2: " << c1 - c2 << std::endl;
	std::cout << "c1 * c2: " << c1 * c2 << std::endl;
	std::cout << "c1 / c2: " << c1 / c2 << std::endl;

	std::cout << "c1.conj(): " << c1.conj() << std::endl;

	std::cout << std::endl; // DELIMITER

	/* 1.2 Vector4 */

	Vector4 v1(1, 2, 3, 4);
	Vector4 v2(4, 0, 0, 0);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	std::cout << "v1 + v2: " << v1 + v2 << std::endl;
	std::cout << "v1 - v2: " << v1 - v2 << std::endl;
	std::cout << "v1 * 2: " << v1 * 2 << std::endl;
	std::cout << "v1 / 2: " << v1 / 2 << std::endl;
	std::cout << "v2.length(): " << v2.length() << std::endl;
	std::cout << "v2.normalize(): " << v2.normalize() << std::endl;

	std::cout << std::endl; // DELIMITER

	/* 2 Vector2 */

	Vector2 v3(1, 2);
	Vector2 v4(3, 4);

	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;

	std::cout << "v3.cross(v4): " << v3.cross(v4) << std::endl;

	std::cout << std::endl; // DELIMITER

	/* 3 ChessMoves */

	ChessMoves cm;
	ChessPiece wcp(CHESS_PIECE::PAWN);
	ChessPiece bcp(CHESS_PIECE::KNIGHT);

	cm.push_back(ChessMove(CHESS_PLAYER::WHITE, wcp, 3, 1));
	cm.push_back(ChessMove(CHESS_PLAYER::BLACK, bcp, 2, 1));
	cm.push_back(ChessMove(CHESS_PLAYER::WHITE, wcp, 3, 2));
	cm.push_back(ChessMove(CHESS_PLAYER::BLACK, bcp, 3, 2));

	ChessMove* m;
	
	m = cm.lastMoveTo(3, 2);
	if (m != nullptr) print(*m);

	cm.pop_back();

	m = cm.lastMoveTo(3, 2);
	if (m != nullptr) print(*m);

	std::cout << std::endl; // DELIMITER

	/* 4 list (bidirectional linked list) */

	std::list<Vector2> l;

	Vector2 vec1(1, 2);
	l.push_back(vec1);

	Vector2* vecP1 = &l.back();
	std::cout << "vecP1: " << vecP1 << std::endl;
	std::cout << "*vecP1: " << *vecP1 << std::endl;

	l.push_front(Vector2(2, 3));
	std::cout << "l.push_front(Vector2(2, 3)" << std::endl;
	std::cout << "vecP1: " << vecP1 << std::endl;
	std::cout << "*vecP1: " << *vecP1 << std::endl;

	std::cout << std::endl; // DELIMITER

	return 0;

}