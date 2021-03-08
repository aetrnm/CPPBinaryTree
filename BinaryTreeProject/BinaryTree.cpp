#include "BinaryTree.h"

#include <iostream>

BinaryTree::BinaryTree() {
	root_ = nullptr;
}

void BinaryTree::add(const int value) {
	if (root_) {
		root_->add(value);
	}
	else {
		root_ = new Cell(value);
	}
}

bool BinaryTree::contains(const int value) const {
	if(root_) {
		return root_->contains(value);
	}
	return false;
}

void BinaryTree::remove(const int value) {
	if(root_) {
		if (!root_->contains(value)) {
			std::cout << "Value not in tree" << std::endl;
			return;
		}
		root_ = root_->remove_in_sub_tree(value);
	}
}

int BinaryTree::get_height() const {
	if(root_) {
		return root_->get_height_of_sub_tree();
	}
	return 0;
}

void BinaryTree::print_tree() const {
	if(root_) {
		root_->print_sub_tree();
		std::cout << std::endl;
	}
	else {
		std::cout << "Tree is empty!" << std::endl;
	}
}