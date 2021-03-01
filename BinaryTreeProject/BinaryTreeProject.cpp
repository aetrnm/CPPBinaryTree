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
	
	try {
		binary_tree->remove(32);
	} catch(...) {
		cout << "value not in tree" << endl;
	}
	binary_tree->print_tree();
}

// Checking with a test print showed that the function correctly finds a replacement cell  