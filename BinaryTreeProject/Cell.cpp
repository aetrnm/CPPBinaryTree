#include "Cell.h"

Cell::Cell(int value)
{
	this->value_ = value;
}

void Cell::add(int value)
{
	if(value < this->value_)
	{
		assign_value_to_cell(value, left_cell_);
	}
	else
	{
		assign_value_to_cell(value, right_cell_);
	}
}

void Cell::assign_value_to_cell(int value, Cell* cell)
{
	if(!cell)
	{
		cell = new Cell(value);
	}
	else
	{
		cell->add(value);
	}
}

bool Cell::contains(int value)
{
	if(this->value_ == value)
	{
		return true;
	}
	if(value < this->value_)
	{
		if(left_cell_)
		{
			return left_cell_->contains(value);
		}
		return false;
	}
	if(right_cell_)
	{
		return right_cell_->contains(value);
	}
	return false;
}
