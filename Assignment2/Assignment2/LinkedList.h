#pragma once
#include <iostream>
using namespace std;


template <typename Item_Type> 
struct Node {
	Item_Type data;
	Node<Item_Type>* nextPtr = nullptr;
	Node(Item_Type data2) { data = data2; nextPtr = nullptr; } //constructor declaration for Node
};


template <typename Item_Type>
class SingleLinkedList {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	int size;

public:
	SingleLinkedList();

	void push_front(const Item_Type& item);
	void push_back(const Item_Type& item);

	void pop_front();
	void pop_back();

	Item_Type& front();
	Item_Type& back();
	bool empty();

	void insert(size_t index, const Item_Type& item);
	bool remove(size_t index);
	size_t find(const Item_Type& item);

	
	void printList();
};









