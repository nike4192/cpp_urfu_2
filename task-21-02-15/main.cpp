#include <iostream>
#include <list>
#include <cmath>

#include "Complex.h" // 1.1
#include "Vector4.h" // 1.2
#include "Amperage.h" // 1.3
#include "Vector2.h" // 2
#include "ChessBoard.h" // 3
#include "PhysForce.h" // 5
#include "PhysLength.h" // 5

std::ostream& operator<< (std::ostream& os, const Complex& c) // Complex
{
	os << "complex(" << c.getReal() << ", " << c.getImag() << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, const Vector4& v) // Vector4
{
	os << "vec4(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ", " << v.getW() << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, const Vector2& v) // Vector2
{
	os << "vec2(" << v.getX() << ", " << v.getY() << ')';

	return os;
}

std::ostream& operator<< (std::ostream& os, const PhysicalValue& pv) // PhysicalValue
{
	pv.print();

	return os;
}

template<typename T>
void print(T ivalue)
{
	std::cout << ivalue << std::endl;
}

void printPieceExist(ChessBoard cb, int x, int y);

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

	/* 1.3 Amperage */

	Amperage a(3);

	a.getValue();
	a.getValue();
	a.getValue();

	std::cout << "Access count a: " << a.getAccessCounter() << std::endl;

	std::cout << std::endl; // DELIMITER

	/* 2 Vector2 */

	Vector2 v3(1, 2);
	Vector2 v4(3, 4);

	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;

	std::cout << "v3.cross(v4): " << v3.cross(v4) << std::endl;

	std::cout << std::endl; // DELIMITER

	/* 3 ChessMoves */

	ChessBoard cb;

	int x1 = 1, y1 = 1;
	cb.setPieceAt(x1, y1, &ChessPiece());
	printPieceExist(cb, x1, y1);

	cb.popPieceAt(x1, y1);
	printPieceExist(cb, x1, y1);

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

	/* 5 PhysicalValues */

	PhysForce pf(40);
	PhysLength pl(10);

	std::cout << "N / m2 ~ " << pf / (pl * pl) << std::endl; // Pa = N / m2
	std::cout << "N * m ~ " << pf * pl << std::endl; // Additionaly J = N * m
	std::cout << "m * m ~ " << pl * pl << std::endl; // m^2
	std::cout << "m * m * m ~ " << pl * pl * pl << std::endl; // m^3

	return 0;

}

void printPieceExist(ChessBoard cb, int x, int y)
{
	ChessPiece* cptr = cb.getPieceAt(x, y);
	if (cptr != nullptr)
		std::cout << "Has chess piece at " << x << ":" << y << std::endl;
	else
		std::cout << "Hasn't chess piece at " << x << ":" << y << std::endl;
}