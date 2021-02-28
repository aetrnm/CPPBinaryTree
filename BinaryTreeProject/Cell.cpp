#include "Cell.h"

Cell::Cell(int value) {
	this->value_ = value;
	this->left_cell_ = nullptr;
	this->right_cell_ = nullptr;
}

void Cell::add(int value) {
	Cell** cell = nullptr;
	if (value < this->value_) {
		cell = &left_cell_;
	}
	else {
		cell = &right_cell_;
	}

	if (!*cell) {
		*cell = new Cell(value);
	}
	else {
		(*cell)->add(value);
	}
}

bool Cell::contains(int value) {
	if (this->value_ == value) {
		return true;
	}
	if (value < this->value_) {
		if (left_cell_) {
			return left_cell_->contains(value);
		}
		return false;
	}
	if (right_cell_) {
		return right_cell_->contains(value);
	}
	return false;
}
