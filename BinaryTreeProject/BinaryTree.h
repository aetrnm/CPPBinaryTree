#pragma once
#include "Cell.h"

class BinaryTree {
public:
	BinaryTree();

	void add(int value);
	bool contains(int value) const;
	void print_tree() const;
	void remove(int value);
	int get_height() const;

private:
	Cell* root_;
	void remove_root();
};
