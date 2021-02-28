#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree* binary_tree = new BinaryTree();

	(*binary_tree).add(10);
	(*binary_tree).add(4);
	(*binary_tree).add(22);
	(*binary_tree).add(8);
	(*binary_tree).add(7);
	(*binary_tree).add(9);
	(*binary_tree).add(15);
	(*binary_tree).add(31);

	//cout << (*binary_tree).contains(32) << endl;

	binary_tree->print_tree();
}
