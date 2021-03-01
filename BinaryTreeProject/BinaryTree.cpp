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
		throw "Value not in tree";
	}
	root_->remove_in_sub_tree(value);
}

void BinaryTree::print_tree() {
	print_subTree(root_);
}

void BinaryTree::print_subTree(Cell* cell) {
	if (cell) {
		print_subTree(cell->left_cell);
		std::cout << cell->value_ << std::endl;
		print_subTree(cell->right_cell);
	}
}
