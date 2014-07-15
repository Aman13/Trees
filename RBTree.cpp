//#ifdef RBTree_H

#include "RBTree.h"

#include <string>
#include <stdexcept>

RBTree::RBTree() : root(NULL), grandpa(NULL), uncle(NULL), counter(0) {
	std::cout << "Rb tree constructor" << std::endl;

}

bool RBTree::insert(int value)	{

	Node* newNode = new Node(value);
	Node* pos = root;
	Node* temp = root;

	if(root == NULL)	{
		std::cout <<"inserting root" << std::endl;
		root = newNode;
		root->parent = NULL;
		fixTree(root);
		counter++;
		return true;
	}

	bool insertion = false;

	while(insertion == false)	{

		if(value == pos->data)	{
			return false;
		}

		if(value < pos->data)	{
			std::cout << "value is smaller than parent" << std::endl;
			if(pos->left == NULL)	{
				std::cout <<"found NULL spot to insert" << std::endl;
				pos->left = newNode;
				temp = newNode;
				temp->parent = pos;
				fixTree(temp);
				counter++;
				insertion = true;
			}
			pos = pos->left;
		}
		if(value > pos->data)	{
			std::cout << "value is larger than parent" << std::endl;
			if(pos->right == NULL)	{
				std::cout <<"found NULL spot to insert" << std::endl;
				pos->right = newNode;
				temp = newNode;
				temp->parent = pos;
				fixTree(temp);
				counter++;
				insertion = true;
				std::cout << "does it fail here" << std::endl;
			}
			pos = pos->right;
		}
	}
	return insertion;
}

void RBTree::grandpaFinder(Node* value)	{
	std::cout << "Grandpa finder for value: " << value->data << std::endl;
	if((value != NULL) && (value->parent != NULL))	{
		grandpa = value->parent->parent;
	}else	{
		grandpa = NULL;
	}
}

void RBTree::uncleFinder(Node* value)	{
	std::cout <<"uncle finder for value: " << value->data << std::endl;
	grandpaFinder(value);
	if(grandpa == NULL)	{
		uncle = NULL; //No grandparent, no existing uncle
	}else if(value->parent == grandpa->left)	{
		uncle = grandpa->right;
	}else if(value->parent == grandpa->right)	{
		uncle = grandpa->left;
	}

}


void RBTree::fixTree(Node* value)	{

	insertCase1(value);

	/*int x = value->data;
	bool y = value->isBlack;
	std::cout << "value: " << x << std::endl << "value colour is now: " << y << std::endl;
	Node* temp = value;
	
	int x = temp->data;
	std::cout << "Entered Fixtree node value is: " << x << std::endl;
	*/
}
/*
void RBTree::rightR(Node* value)	{
	Node* y;
	y = value->left;
	if(y->right != NULL)	{
		y->right->parent = value;
		value->left = y->right;
	}
	if(value->parent == NULL)	{
		y->parent = NULL;
		root = y;
	}else	{
		if( value == (value->parent->left))	{
			value->parent->left = y;
			y->parent = value->parent;
		}else	{
			value->parent->right = y;
			y->parent = value->parent;
		}
	}
	y->right = value;
	value->parent = y;
}

void RBTree::leftR(Node* value)	{
	Node* y;
	y = value->right;
	if(y->left != NULL)	{
		y->left->parent = value;
		value->right = y->left;
	}
	if(value->parent == NULL)	{
		y->parent = NULL;
		root = y;
	}else	{
		if(value == (value->parent->left))	{
			value->parent->left = y;
			y->parent = value->parent;
		}	else	{
			value->parent->right = y;
			y->parent = value->parent;
		}
	}
	y->left = value;
	value->parent = y;
}
*/


void RBTree::rightR(Node* value)	{
	std::cout << "right rotating: " << value->data << std::endl;
	if(value->parent == NULL)	{
		value->left->parent = NULL;
		root = value->left;
	}else if(value == value->parent->left)	{
		value->parent->left = value->left;
		value->left->parent = value->parent;
	}else if(value == value->parent->right)	{
		value->parent->right = value->left;
		value->left->parent = value->parent;
	}
	value->parent = value->left;
	std::cout <<"value parent left data: " << value->parent->left->data << std::endl
	<< "value parent is: " << value->parent->data << std::endl;
	if((value->parent==NULL)&&(value->parent->right != NULL)){
		value->left = value->parent->right;
	}else	{
		value->left = NULL;
	}
	value->parent->right = value;

}

void RBTree::leftR(Node* value)	{
	std::cout << "Left rotating: " << value->data << std::endl;
	if(value->parent == NULL)	{
		value->right->parent = NULL;
		root = value->right;
	}else if(value == value->parent->left)
	{
		value->parent->left = value->right;
		value->right->parent = value->parent;
	}else if(value == value->parent->right)
	{
		value->parent->right = value->right;
		value->right->parent = value->parent;
	}
	value->parent = value->right;
	if(value->parent->left != NULL)	{
		value->right = value->parent->left;
	}else	{
		value->right = NULL;
	}
	value->parent->left = value;
}


void RBTree::insertCase1(Node* value)	{
	std::cout << "case 1" << std::endl;
	if(value-> parent == NULL)	{
		value->isBlack = 1;
	}else insertCase2(value);
}

void RBTree::insertCase2(Node* value)	{
	std::cout << "case 2" << std::endl;
	if(value->parent->isBlack == 1)	{
		//tree is valid
	}else	{
		insertCase3(value);
	}
}

void RBTree::insertCase3(Node* value)	{
	std::cout << "case 3 " << std::endl;
	uncleFinder(value);
	if((uncle != NULL)&&(uncle->isBlack == 0))	{
		value->parent->isBlack = 1;
		uncle->isBlack = 1;
		grandpaFinder(value);
		grandpa->isBlack = 0;
		insertCase1(grandpa);
	}else	{
		insertCase4(value);
	}
}

void RBTree::insertCase4(Node* value)	{
	std::cout << "case 4 " << std::endl;
	grandpaFinder(value);
	if((value == value->parent->right)&&(value->parent == grandpa->left))	{
		leftR(value->parent);
		value = value->left;
	}
	else if((value == value->parent->left)&&(value->parent == grandpa->right))	{
		rightR(value->parent);
		value = value->right;
	}
	insertCase5(value);
}

void RBTree::insertCase5(Node* value)	{

	std::cout << "case 5 " << std::endl;
	grandpaFinder(value);
	value->parent->isBlack = 1;

	grandpa->isBlack = 0;
	if(value == value->parent->left)	{
		rightR(grandpa);
	}else	{
		leftR(grandpa);
	}

	std::cout << "Leaving case 5" << std::endl;
}

void RBTree::PrintInOrder()	{
	std::cout << "print in order" << std::endl;
	std::cout << "the root is: " << root->data << std::endl;
	quickprint(root);
	std::cout << std::endl << "-----------------" << std::endl;
}

void RBTree::quickprint(Node* value)	const	{

	if(root != NULL)	{
		if(value->left != NULL)	{
			quickprint(value->left);
		}
		if(value->isBlack == 0)	{
			std::cout << value->data << "Red, ";
		}
		if(value->isBlack != 0)	{
			std::cout << value->data << "Black, ";
		}
		if(value->right != NULL)	{
			quickprint(value->right);
		}
	}else	{
		std::cout << "tree is empty" << std::endl;
	}
}
/*
int RBTree::dump(int n)	{
	int* newArray;
	int* entry = &n;
	newArray = new int[counter];
	newArray = inorder(root, newArray, entry);
	return *newArray;
}

int RBTree::inorder(Node* value, int arr[], int n)	{

}
*/

int RBTree::size()	const	{
	return counter;
}
