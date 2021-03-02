#pragma once
class Cell {
public:
	int value_;
	Cell(int value);

	void add(int value);
	bool contains(int value);
	Cell* remove_in_sub_tree(int value);

	Cell* left_cell;
	Cell* right_cell;
	
	Cell* find_and_remove_min_cell_in_sub_tree();
private:
	Cell* find_cell_by_value(int value);
};
