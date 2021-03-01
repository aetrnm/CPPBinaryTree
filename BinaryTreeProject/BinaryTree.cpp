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
	if(!root_->contains(value)) {
		std::cout << "Value not in tree" << std::endl;
		return;
	}	
	root_->remove_in_sub_tree(value);
}

void BinaryTree::print_tree() {
	print_sub_tree(root_);
}

void BinaryTree::print_sub_tree(Cell* cell) {
	if (cell) {
		print_sub_tree(cell->left_cell);
		std::cout << cell->value_ << " ";
		print_sub_tree(cell->right_cell);
	}
}
