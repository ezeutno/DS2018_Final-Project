#include <iostream>
using namespace std;

#ifndef SIMPLELIBRARY_LINKEDLISTADT_H
#define SIMPLELIBRARY_LINKEDLISTADT_H

template<typename T>
struct NODE {
	T data;
	NODE<T> *link = NULL;
	NODE<T>() {};
	NODE<T>(T data, NODE<T> *link) {
		this->data = data;
		this->link = link;
	}
};

template<typename T>
class linkedlistADT {
public:

	//    Iterator
	class iterator {
	public:
		NODE<T> *current;
		T& operator*() const {
			return current->link->data;
		};
		iterator operator++(int) {
			current = current->link;
			return *this;
		};
		bool operator!=(const iterator &right) {
			return current != right.current;
		};
		iterator(NODE<T> *ptr) {
			current = ptr;
		};
		iterator() {
			current = NULL;
		};
	};
	//End of Iterator

	T& front();
	T& back();
	iterator begin();
	iterator end();
	iterator insert(iterator &it, const T &book);
	iterator erase(iterator pos);
	iterator find(iterator begin, iterator end, const T &book);
	iterator push_front(const T &book);
	iterator push_back(const T &book);

	void clear();
	bool empty();
	int size();

	linkedlistADT();
	~linkedlistADT();

private:
	int count;
	NODE<T> *head;
	NODE<T> *tail;
};

#endif //SIMPLELIBRARY_ITERATOR_H