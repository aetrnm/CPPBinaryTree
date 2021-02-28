#pragma once
class Cell
{
public:
	int value_;
	Cell(int value);
	
	void add(int value);
	bool contains(int value);
	Cell* find(int value);
	Cell* find_min();

	Cell* left_cell;
	Cell* right_cell;

	Cell* parent_cell;
};