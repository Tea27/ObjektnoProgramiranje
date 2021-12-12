#include "Board_Point.hpp"
using namespace std;

int main(void) {
	Point p1(2, 2), p2(2, 8), p3(2, 8), p4(16, 8);
	Board myBoard(10, 20);
	myBoard.draw_line(p1, p2, 'x');
	myBoard.draw_line(p3, p4, 'x');
	myBoard.display();
}