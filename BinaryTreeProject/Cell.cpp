#include "Cell.h"

Cell::Cell(int value) {
	this->value_ = value;
	this->left_cell = nullptr;
	this->right_cell = nullptr;
}

void Cell::add(int value) {
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

bool Cell::contains(int value) {
	return find(value) != nullptr;
}

Cell* Cell::find(int value) {
	if (this->value_ == value) {
		return this;
	}
	if (value < this->value_) {
		if (left_cell) {
			return left_cell->find(value);
		}
	}
	if (right_cell) {
		return right_cell->find(value);
	}
	return nullptr;
}

Cell* Cell::find_min() {
	if(this->left_cell) {
		if(!this->left_cell->left_cell) {
			return this;
		}
		return this->left_cell->find_min();
	}
	return nullptr;
}
