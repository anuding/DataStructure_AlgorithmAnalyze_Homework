#include <iostream>
using namespace std;

// Binary tree node abstract class

// Simple binary tree node implementation
template <typename E>
class BinNode {
private:

	E it; // The node’s value
	BinNode* lc; // Pointer to left child
	BinNode* rc; // Pointer to right child
public:
	// Two constructors -- with and without initial values
	BinNode() { lc = rc = NULL; }
	BinNode(E e, BinNode* l = NULL, BinNode* r = NULL)
	{
		it = e; lc = l; rc = r;
	}
//	˜BinNode() {} // Destructor
				  // Functions to set and return the value and key
	E& element() { return it; }

	// Functions to set and return the children
	inline BinNode* left() const { return lc; }
	void setLeft(BinNode<E>* b) { lc = (BinNode*)b; }
	inline BinNode* right() const { return rc; }
	void setRight(BinNode<E>* b) { rc = (BinNode*)b; }
	// Return true if it is a leaf, false otherwise
	bool isLeaf() { return (lc == NULL) && (rc == NULL); }
};