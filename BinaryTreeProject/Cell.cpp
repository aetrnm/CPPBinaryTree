#include "Cell.h"

#include <iostream>

Cell::Cell(const int value) {
	this->value_ = value;
	this->left_cell = nullptr;
	this->right_cell = nullptr;
}

int Cell::get_value() const {
	return value_;
}

void Cell::add(const int value) {
	Cell** cell = nullptr;
	if (value < this->value_) {
		cell = &left_cell;
	}
	else {
		cell = &right_cell;
	}

	if (!*cell) {
		*cell = new Cell(value);
	}
	else {
		(*cell)->add(value);
	}
}

bool Cell::contains(const int value) {
	return find_cell_by_value(value);
}

Cell* Cell::find_cell_by_value(const int value) {
	if (this->value_ == value) {
		return this;
	}
	if (value < this->value_) {
		if (left_cell) {
			return left_cell->find_cell_by_value(value);
		}
	}
	if (right_cell) {
		return right_cell->find_cell_by_value(value);
	}
	return nullptr;
}

Cell* Cell::find_and_remove_min_cell_in_sub_tree() {
	if (this->left_cell && !this->left_cell->left_cell) {
		Cell* found = this->left_cell;
		this->left_cell = found->right_cell;
		return found;
	}
	return this->left_cell->find_and_remove_min_cell_in_sub_tree();
}

Cell* Cell::remove_in_sub_tree(const int value) {
	if (value < this->value_) {
		this->left_cell = this->left_cell->remove_in_sub_tree(value);
		return this;
	}
	if (value > this->value_) {
		this->right_cell = this->right_cell->remove_in_sub_tree(value);
		return this;
	}
	if (!this->right_cell) { // 1/2 cases
		return this->left_cell;
	}
	if (!this->right_cell->left_cell) { // 3 case
		Cell* cell_to_return = this->right_cell;
		cell_to_return->left_cell = this->left_cell;
		delete this;
		return cell_to_return;
	}
	// 4 case 
	Cell* cell_to_remove = this->right_cell->find_and_remove_min_cell_in_sub_tree();
	cell_to_remove->left_cell = this->left_cell;
	cell_to_remove->right_cell = this->right_cell;
	return cell_to_remove;
}

void Cell::print_sub_tree() const {
	if(left_cell) {
		left_cell->print_sub_tree();
	}
	std::cout << value_ << " ";
	if(right_cell) {
		right_cell->print_sub_tree();
	}
}

int Cell::get_height_of_sub_tree() const {
	if(left_cell && right_cell) {
		return 1 + std::max(left_cell->get_height_of_sub_tree(), right_cell->get_height_of_sub_tree());
	}
	if(right_cell) {
		return 1 + right_cell->get_height_of_sub_tree();
	}
	if(left_cell) {
		return 1 + left_cell->get_height_of_sub_tree();
	}
	return 0;
}
