#pragma once
#include <vector>

#include "Cell.h"

class BinaryTree {
public:
	//Constructor
	BinaryTree();
	
	void add(int value);
	bool contains(int value) const;
	void print_tree();
	void remove(int value) const;

private:
	Cell* root_;

	void print_sub_tree(Cell* cell);
};
