#pragma once
#include <vector>

#include "Cell.h"

class BinaryTree {
public:
	BinaryTree();
	void add(int value);
	bool contains(int value) const;
	void print_tree() const;

private:
	Cell* root_;

	std::vector<int> sorted_tree_;
	static void print_subtree(Cell* cell);
};
