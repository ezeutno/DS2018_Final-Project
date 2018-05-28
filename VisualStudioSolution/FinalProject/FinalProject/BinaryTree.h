#include <iostream>
#include "LinkList.h"
using namespace std;



#ifndef BinaryTree_H
#define BinaryTree_H

struct node {
	node* right;
	node* left;
	node* up;
	int count;
	linkedlistADT<char> route;
};

class BinaryTree {
private:
	node * head;
	node * current;
public:
	BinaryTree();
	void insert(linkedlistADT<char> data);
	bool isEmpty() const;
	void getLowest();

};


#endif 



