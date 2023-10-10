#include "LinkedList.h"

//explicit template initiation
template class SingleLinkedList<string>;


//constructor
template <typename Item_Type>
SingleLinkedList<Item_Type>::SingleLinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
};



//push item in front of list and updates head. if list empty, header and tail is both set to new Node. size increase.
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_front(const Item_Type& item) {
	Node<Item_Type>* newNode = new Node<Item_Type>(item);
	if (head == nullptr) { 
		head = newNode;
		tail = newNode;
	}
	else { 
		newNode->nextPtr = head;
		head = newNode;
	}
	size++;
}
//push item in back of the list and update tail. if list empty, header and tail is both set to new Node. size increase.
template <typename Item_Type>
void SingleLinkedList<Item_Type>::push_back(const Item_Type& item) {
	Node<Item_Type>* newNode = new Node<Item_Type>(item);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->nextPtr = newNode;
		tail = newNode;
	}
	size++;
}




//pops an item in front of list. if header == tail (assuming there is one item left), both become nullptr that make list empty. size decrease.
//if list is already empty, throw error
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_front() {
	if (head == nullptr) throw runtime_error("Cant pop front\n");
	else if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<Item_Type>* delNode = head;
		head = head->nextPtr; //header becomes header next pointer
		delete delNode; //delNode containing original header gets deleted
		delNode = nullptr;
	}
	size--;
}
//pops an item in front of list. if tail == header (assuming there is one item left), both become nullptr that make list empty. size decrease.
//if size is already empty, throw error
template <typename Item_Type>
void SingleLinkedList<Item_Type>::pop_back() {
	if (tail == nullptr) throw runtime_error("Cant pop back\n");
	else if (tail == head) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<Item_Type>* currentNode = head;
		while (currentNode->nextPtr != tail) currentNode = currentNode->nextPtr; //iterates until it reaches the second last node

		tail = currentNode;  //tail becomes current node (or second last node)
		tail->nextPtr = nullptr; //tail next pointer becomes null
		delete currentNode->nextPtr; //CurrentNode nextPtr gets deleted 
		currentNode->nextPtr = nullptr;
	}
	size--;
}






//return item from front of list, else throw error if empty
template <typename Item_Type>
Item_Type& SingleLinkedList<Item_Type>::front() { 
	if (!empty()) return head->data; 
	else throw std::runtime_error("No header - empty list\n");
};

//return item from back of list, else throw error if empty
template <typename Item_Type>
Item_Type& SingleLinkedList<Item_Type>::back() { 
	if (!empty()) return tail->data; 
	else throw std::runtime_error("No tail - empty list\n");
};

//return a bool state if list is empty
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::empty() { return (head == nullptr && tail == nullptr); }; 





//insert item in list from given index. if index is beyond end of list, item is inserted to back of list. size increase.
template <typename Item_Type>
void SingleLinkedList<Item_Type>::insert(size_t index, const Item_Type& item) {
	if (index >= size) push_back(item); //if index is beyond list size, item is push to the back of list
	else if (index == 0) push_front(item); //if index is 0, item is push to the front of list
	else {
		Node<Item_Type>* newNode = new Node<Item_Type>(item);
		Node<Item_Type>* currentNode = head;
		for (size_t i = 1; i < index; i++) currentNode = currentNode->nextPtr; //iterate from pos 1 to index
		newNode->nextPtr = currentNode->nextPtr; //grabs the rest of nextPtr
		currentNode->nextPtr = newNode;
		size++;
	}
}

//remove item from list from given index. size decrease. Return true if successful, else return false if index beyond end of list. 
template <typename Item_Type>
bool SingleLinkedList<Item_Type>::remove(size_t index) {
	if (index >= size) return false;
	else if (index == 0) pop_front();
	else if (index == size - 1) pop_back();
	else {
		Node<Item_Type>* currentNode = head;
		Node<Item_Type>* nextNode = head->nextPtr;
		for (size_t i = 1; i < index; i++) {
			currentNode = nextNode;
			nextNode = nextNode->nextPtr;
		}
		currentNode->nextPtr = nextNode->nextPtr;
		delete nextNode;
		nextNode = nullptr;
		size--;
	}
	return true;
}

//return the first occurence position of item if found. If not found, then return size of list.
template <typename Item_Type>
size_t SingleLinkedList<Item_Type>::find(const Item_Type& item) {
	Node<Item_Type>* currentNode = head;
	int pos = 0;
	while (currentNode != nullptr) { //iterator
		if (currentNode->data == item) return pos; 
		currentNode = currentNode->nextPtr;
		pos++;
	}
	return size; //if item not found, size returned
}




//print current linked list with all items shown in order, else print "list is empty"
template <typename Item_Type>
void SingleLinkedList<Item_Type>::printList() {
	Node<Item_Type>* currentNode = head;
	if (empty()) cout << "List is Empty";
	while (currentNode != nullptr) {
		cout << "->" << currentNode->data;
		currentNode = currentNode->nextPtr;
	}
	cout << "\n";
}



