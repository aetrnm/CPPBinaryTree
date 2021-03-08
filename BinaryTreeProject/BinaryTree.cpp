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
		if (root_->get_value() == value) {
			remove_root();
		}
		else {
			root_->remove_in_sub_tree(value);
		}
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

void BinaryTree::remove_root() {
	Cell* cell_to_replace = nullptr;
	if(root_->left_cell || root_->right_cell) {
		if (!root_->left_cell) {
			cell_to_replace = new Cell(root_->right_cell->get_value());
		}
		else if (!root_->right_cell) {
			cell_to_replace = new Cell(root_->left_cell->get_value());
		}
		else if (root_->right_cell) {

			cell_to_replace = root_->right_cell->find_and_remove_min_cell_in_sub_tree();
			cell_to_replace->right_cell = root_->right_cell;
		}
		else if (root_->left_cell) {
			cell_to_replace->left_cell = root_->left_cell;
		}
	}
	root_ = cell_to_replace;
}