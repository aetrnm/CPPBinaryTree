#pragma once
#include <vector>

#include "Cell.h"

class BinaryTree
{
public:
	BinaryTree();
	void add(int value);
	bool contains(int value);
	void print_field();

private:
	Cell* root_{};
	std::vector<int> sorted_tree_;
	void get_sorted_tree_from_specific_cell(Cell* cell);
};

