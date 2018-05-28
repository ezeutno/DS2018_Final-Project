#include "BinaryTree.h"



BinaryTree::BinaryTree(){
	head = NULL;
}

void BinaryTree::insert(linkedlistADT<char> data){
	if (head == NULL) {
		head = new node();
		head->count = data.size();
		head->route = data;
		head->right = NULL;
		head->left = NULL;
		head->up = NULL;
	}else {
		current = head;
		if (current->count > data.size()) {
		}
	}
}

bool BinaryTree::isEmpty() const{
	return head == NULL;
}
