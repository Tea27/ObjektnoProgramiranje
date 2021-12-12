#include <iostream>
#include <cmath>
#include "Board_Point.hpp"

using namespace std;

void Board::allocateMatrix(int rows, int cols) {
	matrix = new char* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new char[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || j == 0 || j == cols - 1 || i == rows - 1) {
				matrix[i][j] = 'o';
			}
			else {
				matrix[i][j] = ' ';
			}
		}
	}
}

Board::Board() {
	rows = 20; 
	cols = 20; 
	allocateMatrix(rows, cols);
}

Board::~Board() {
	rows = 0;
	cols = 0;

	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

Board::Board(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	allocateMatrix(rows, cols);
}

Board::Board(const Board& board) {
	rows = board.rows;
	cols = board.cols;

	matrix = new char* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new char[cols];

	memcpy(matrix, board.matrix, cols*sizeof(rows));
}

Board::Board(Board&& board){
	rows = board.rows;
	cols = board.cols;
	matrix = board.matrix;

	board.matrix = nullptr;
	board.cols = 0;
	board.rows = 0;
}

void Board::draw_char(Point& point, char ch) {
	int row = round(point.getX());
	int column = round(point.getY());
	matrix[row][column] = ch;
}

void Board::draw_up_line(Point& point, char ch) {
	int row = round(point.getX());
	int column = round(point.getY());
	for (int r = 1; r < row; r++) {
		matrix[r][column] = ch;
	}
}

void Board::draw_line(Point& point1, Point& point2, char ch) {
	int x1 = round(point1.getX());
	int y1 = round(point1.getY());
	int x2 = round(point2.getX());
	int y2 = round(point2.getY());

	if (x1 < 0 || x1 > cols || x2 > cols || y1 < 0 || y1 > rows || y2 > rows) {
		cout << "wrong dimensions\n";
		return;
	}

	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	if (x1 == x2 && y1 == y2) {
		matrix[x1][y1] = ch;
	}

	while (x1 != x2 || y1 != y2) {

		matrix[y1][x1] = ch;

		if (x1 != x2 && y1 != y2) x1++, y1++;
		else if (x1 == x2 && y1 != y2) y1++;
		else if (x1 != x2 && y1 == y2) x1++;
	}

}

void Board::display()
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			cout << matrix[i][j];
		}
		cout << "\n";
	}
}