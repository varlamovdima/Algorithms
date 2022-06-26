// BTS Construction
// Write a BTS class for a Binary Search Tree. The class should support:
// * Inserting values with the insert method
// * Rmoving values with thre remove method; this method should only remove the first
// instance of a given value.
// * Searching for values with the contains method.
//
// Note that you can't remove values from a single-node tree. In other words, calling the // remove method on a single-node tree should simply not do anything.
//
// Each BTS node had an integer value, a left child node, and a right child node.
// A node is said to be a valid BTS node if and only if it satisfies the BTS property:
// its value is strictly greater than the values of every node to its left value
// is less than or equal to the values of every node to its right; and its children 
// nodes are either valid BTS nodes themselves or None / NULL

#include <vector>
using namespace std;

class BST {
public:
	int value;
	BST *left;
	BST *right;

	BST(int val){
		value = val;
		left = nullptr;
		right = nullptr;
	}

	BST &insert(int val){
		if(val<value){
			if(left == nullptr){
				BST *newBST = new BST(val);
				left = newBST;
			}else{
				left->insert(val);
			}
		}else{
			if(right == nullptr){
				BST *newBST = new BST(val);
				right = newBST;
			}else{
				right->insert(val);
			}
		}
		return *this;
	}

	bool contains(int val){
		if(val<value){
			if(left == nullptr){
				return false;
			}else{
				return left->contains(val);
			}
		}else if(val>value){
			if(right == nullptr){
				return false;
			}else{
				return right->contains(val);
			}
		}else{
			return true;
		}
	}

	BST &remove(int val, BST *parent = nullptr){
		if(val < value){
			if(left != nullptr){
				left->remove(val,this);
			}
		}else if(val > value){
			if(right != nullptr){
				right->remove(val,this);
			}
		}else{
			if(left !=nullptr && right !=nullptr){
				value = right->getMinValue();
				right->remove(value,this);
			}else if(parent == nullptr){
				if(left != nullptr){
					value = left->value;
					right = left->right;
					left = left->left;
				}else if(right != nullptr){
					value = right->value;
					left = right->left;
					right = right->right;
				}else{

				}
			}else if(parent->left == this){
				parent->left = left != nullptr ? left : right;
			}else if(parent->right == this){
				parent->right = left !=nullptr ? left : right;
			}
		}
		return *this;
	}

	int getMinValue(){
		if(left==nullptr)
			return value;
		else	
			return left->getMinValue();
	}
};

// BST property: left child node must be less than current node
// right child node must be greater or equal than current node

int main(){

	return 0;
}
	
