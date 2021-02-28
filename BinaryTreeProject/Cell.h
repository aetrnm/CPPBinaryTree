#pragma once
class Cell
{
public:
	Cell(int value);
	void add(int value);
	void assign_value_to_cell(int value, Cell* cell);
	bool contains(int value);
	Cell* left_cell_;
	Cell* right_cell_;
	int value_;
};