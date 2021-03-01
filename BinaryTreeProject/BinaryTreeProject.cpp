#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree* binary_tree = new BinaryTree();

	(*binary_tree).add(10);
	(*binary_tree).add(22);
	(*binary_tree).add(4);
	(*binary_tree).add(15);
	(*binary_tree).add(12321);
	(*binary_tree).add(1);


	binary_tree->print_tree();
}