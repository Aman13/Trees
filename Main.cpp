#include <iostream>

#include "RBTree.h"

int main()	{
	RBTree a1;
//	a1.PrintInOrder();

	a1.insert(40);
	a1.PrintInOrder();
	a1.insert(50);
	a1.PrintInOrder();
	a1.insert(60);
	a1.PrintInOrder();
	a1.insert(55);
	a1.PrintInOrder();
	a1.insert(70);
	a1.PrintInOrder();
	a1.insert(57);
	a1.PrintInOrder();
	a1.insert(59);
	a1.PrintInOrder();
/*	a1.PrintInOrder();
	a1.insert(15);
	a1.PrintInOrder();
	a1.insert(5);
	a1.PrintInOrder();
*/
}