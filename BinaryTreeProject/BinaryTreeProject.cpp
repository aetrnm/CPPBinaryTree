#include <iostream>

#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree* binary_tree = new BinaryTree();

	for(int i = 0; i < 8; i++) {
		int k;
		cin >> k;
		(*binary_tree).add(k);
		binary_tree->remove(k);
		binary_tree->print_tree();
		cout << endl;
	}
	/*(*binary_tree).add(10);
	(*binary_tree).add(4);
	(*binary_tree).add(22);
	(*binary_tree).add(8);
	(*binary_tree).add(7);
	(*binary_tree).add(9);
	(*binary_tree).add(15);
	(*binary_tree).add(31);*/
}