#pragma once
#include "Cell.h"

class BinaryTree {
public:
	//Constructor
	BinaryTree();

	void add(int value);
	bool contains(int value);
	void print_tree();
	void remove(int value);
	int get_height();

private:
	Cell* root_;

	void print_sub_tree(Cell* cell);

	void remove_root();

	int get_height_of_sub_tree(Cell* cell);
};
