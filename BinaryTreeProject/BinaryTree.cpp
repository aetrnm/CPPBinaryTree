#include "BinaryTree.h"

#include <iostream>

BinaryTree::BinaryTree() {
	root_ = nullptr;
}

void BinaryTree::add(int value) {
	if (!root_) {
		root_ = new Cell(value);
	}
	else {
		root_->add(value);
	}
}

bool BinaryTree::contains(int value) const {
	return (*root_).contains(value);
}

void BinaryTree::print_tree() const {
	print_subtree(root_);
}

void BinaryTree::print_subtree(Cell* cell) {
	if (cell) {
		print_subtree(cell->left_cell_);
		std::cout << cell->value_ << std::endl;
		print_subtree(cell->right_cell_);
	}
}
