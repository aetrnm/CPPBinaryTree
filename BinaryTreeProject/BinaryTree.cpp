#include "BinaryTree.h"

#include <iostream>

BinaryTree::BinaryTree() = default;

void BinaryTree::add(int value)
{
	if(!root_)
	{
		root_ = new Cell(value);
	}
	else
	{
		root_->add(value);
	}
}

bool BinaryTree::contains(int value)
{
	return (*root_).contains(value);
}

void BinaryTree::print_field()
{
	get_sorted_tree_from_specific_cell(root_);
	for (auto i : sorted_tree_)
	{
		std::cout << i << std::endl;
	}
}

void BinaryTree::get_sorted_tree_from_specific_cell(Cell* cell)
{
	if(cell)
	{
		get_sorted_tree_from_specific_cell(cell->left_cell_);
		sorted_tree_.push_back(cell->value_);
		get_sorted_tree_from_specific_cell(cell->right_cell_);
	}
}