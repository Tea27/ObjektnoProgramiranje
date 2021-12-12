#pragma once
#include <iostream>

class Point {
	double x, y;

public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
};

class Board {
	int rows, cols;
	char** matrix;

public:
	Board();
	~Board();
	Board(int rows, int cols);
	Board(const Board& board);
	Board(Board&& board);
	void draw_char(Point& point, char ch);
	void draw_up_line(Point& point, char ch);
	void draw_line(Point& point1, Point& point2, char ch);
	void display();
	void allocateMatrix(int row, int col);
};

