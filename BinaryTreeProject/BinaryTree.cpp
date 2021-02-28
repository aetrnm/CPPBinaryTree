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

void BinaryTree::remove(int value) const {
	Cell* cellToRemove = root_->find(value);

	if(cellToRemove->right_cell) {
		Cell* replacementCell = cellToRemove->right_cell->find_min_parent();
		if(!replacementCell) {
			replacementCell = cellToRemove->right_cell;
		}
	}

	
}

void BinaryTree::print_tree() {
	print_subtree(root_);
}

void BinaryTree::print_subtree(Cell* cell) {
	if (cell) {
		print_subtree(cell->left_cell);
		std::cout << cell->value_ << std::endl;
		print_subtree(cell->right_cell);
	}
}
