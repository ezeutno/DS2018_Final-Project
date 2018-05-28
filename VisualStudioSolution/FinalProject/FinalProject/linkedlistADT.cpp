#include "LinkList.h"

template<typename T>
linkedlistADT<T>::linkedlistADT() {
	count = 0;
	head = tail = new NODE<T>;
}

template<typename T>
linkedlistADT<T>::~linkedlistADT(){
	clear();
}

template<typename T>
T& linkedlistADT<T>::front() {
	return head->link->data;
}

template<typename T>
T& linkedlistADT<T>::back() {
	return tail->data;
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::begin() {
	return iterator(head);
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::end() {
	return iterator(tail);
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::insert(linkedlistADT::iterator& it, const T& book) {
	NODE<T>* newNode = new NODE<T>(book, it.current->link);
	if (it.current == tail) {
		tail = newNode;
	}
	it.current->link = newNode;
	count++;
	it++;
	return it;
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::erase(iterator pos) {
	NODE<T> *node = pos.current->link;
	pos.current->link = pos.current->link->link;
	if (node == tail) {
		tail = pos.current;
	}
	delete node;
	iterator it = iterator(pos);
	count--;
	return it;
}


template<typename T>
int linkedlistADT<T>::size() {
	return count;
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::find(linkedlistADT::iterator begin, linkedlistADT::iterator end, const T &book) {
	for (begin; begin != end; begin++) {
		if (*begin == book) {
			return begin;
		}
	}
	return end;
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::push_front(const T &book) {
	iterator it = iterator(head);
	NODE<T>* newNode = new NODE<T>(book, it.current->link);
	if (it.current == tail) {
		tail = newNode;
	}
	it.current->link = newNode;
	count++;
	it++;
	return it;
}

template<typename T>
typename linkedlistADT<T>::iterator linkedlistADT<T>::push_back(const T &book) {
	iterator it = iterator(tail);
	NODE<T>* newNode = new NODE<T>(book, it.current->link);
	if (it.current == tail) {
		tail = newNode;
	}
	it.current->link = newNode;
	count++;
	it++;
	return it;
}

template<typename T>
void linkedlistADT<T>::clear() {
	NODE<T> *temp;
	while (head != NULL){
		temp = head;
		head = head->link;
		delete temp;
	}
	tail = NULL;
	count = 0;
}

template<typename T>
bool linkedlistADT<T>::empty() {
	return head == NULL;
}