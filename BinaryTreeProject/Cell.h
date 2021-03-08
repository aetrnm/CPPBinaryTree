#pragma once
class Cell {
public:
	Cell(int value);
	int get_value() const;

	void add(int value);
	bool contains(int value);

	Cell* find_and_remove_min_cell_in_sub_tree();
	Cell* remove_in_sub_tree(int value);
	void print_sub_tree() const;
	int get_height_of_sub_tree() const;
	
private:
	int value_;
	Cell* left_cell;
	Cell* right_cell;
	
	Cell* find_cell_by_value(int value);
};
