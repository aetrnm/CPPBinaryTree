#include "BinaryTree.h"

#include <iostream>
#include <algorithm>

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

bool BinaryTree::contains(int value) {
	return (*root_).contains(value);
}

void BinaryTree::remove(int value) {
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

int BinaryTree::get_height() {
	return std::max(get_height_of_sub_tree(root_->right_cell), get_height_of_sub_tree(root_->left_cell));
}

void BinaryTree::print_tree() {
	if(!root_) {
		std::cout << "Tree is empty!" << std::endl;
	}
	else {
		print_sub_tree(root_);
		std::cout << std::endl;
	}
}

void BinaryTree::print_sub_tree(Cell* cell) {
	if (cell) {
		print_sub_tree(cell->left_cell);
		std::cout << cell->get_value() << " ";
		print_sub_tree(cell->right_cell);
	}
	
}

void BinaryTree::remove_root() {
	Cell* cellToRPLC = nullptr;
	if(root_->left_cell || root_->right_cell) {
		if (!root_->left_cell) {
			cellToRPLC = new Cell(root_->right_cell->get_value());
		}
		else if (!root_->right_cell) {
			cellToRPLC = new Cell(root_->left_cell->get_value());
		}
		else if (root_->right_cell) {

			cellToRPLC = root_->right_cell->find_and_remove_min_cell_in_sub_tree();
			cellToRPLC->right_cell = root_->right_cell;
		}
		else if (root_->left_cell) {
			cellToRPLC->left_cell = root_->left_cell;
		}
	}
	root_ = cellToRPLC;
}

int BinaryTree::get_height_of_sub_tree(Cell* cell) {
	if (!cell) {
		return 0;
	}
	return 1 + std::max(get_height_of_sub_tree(cell->left_cell), get_height_of_sub_tree(cell->right_cell));
}
