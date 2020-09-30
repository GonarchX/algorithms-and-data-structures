#include "../lib/double_linked_list.hpp"

#include <stdexcept>
#include <string>

using namespace std;

//Work with double linked list

void   DoubleLinkedList::pushBack(const int data) //adding to the end of the list
{
	if (size == 0) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->next = new Node(data, tail);
		tail = tail->next;
	}
	size++;
}

void   DoubleLinkedList::pushFront(const int data) //  adding to the beginning of the list
{
	if (size == 0) {
		head = new Node(data);
		tail = head;
	}
	else {
		head->prev = new Node(data, nullptr, head);
		head = head->prev;
	}
	size++;
}

void   DoubleLinkedList::popBack() //  remove the last element
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node *current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

void   DoubleLinkedList::popFront() //  removing the first element
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node *current = head->next;
		current->prev = nullptr;
		delete head;
		head = current;
	}
	size--;
}

void   DoubleLinkedList::insert(int data, const size_t index) //  insert element before element at index
{	
	Node *current = findNode(index);
	
	if (current != head) {
		current->prev->next = new Node(data, current->prev, current);
		current->prev = current->prev->next;
	}
	else {		
		current->prev = new Node(data, nullptr, head);
		head = current->prev;
	}	
	size++;
}

int    DoubleLinkedList::at(const size_t index)
{	
	Node *current = findNode(index);
	return current->data;	
}

void   DoubleLinkedList::remove(const size_t index) //  deleting an element by index
{
	Node *current = findNode(index);
	
	if (size == 1){
		delete current;
		head = nullptr;
		tail = nullptr;
	}
	else if (current == head) {
		current = current->next;
		current->prev = nullptr;
		delete current->prev;
		head = current;
	}
	else if (current == tail) {
		current = current->prev;
		current->next = nullptr;
		delete current->next;
		tail = current;
	}
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
	}
	size--;
}

size_t DoubleLinkedList::getSize() const{return size;} //  getting list size

void   DoubleLinkedList::printToConsole()const //  output of list items to the console
{
	if (!size) cout << "List is empty";
	Node *current = head;
	while(current) {
		cout << current->data << " ";
		current = current->next;
	}
}

void   DoubleLinkedList::clear() //  removing all list items
{
	size_t listSize = size;
	for (size_t count = 0; count < listSize; count++) popBack();
}

void   DoubleLinkedList::set(int data, const size_t index) //  replacing the element by index with the passed element
{
	Node *current = findNode(index);
	current->data = data;
}

bool   DoubleLinkedList::isEmpty() const //  checking if the list is empty
{
	if(getSize()) return true;
    else return false;
}

DoubleLinkedList::Node *DoubleLinkedList::findNode(const size_t index) //Finding the desired node
{
	if (index >= size) throw out_of_range("Index is greater than list size");
	Node *current;

	//If the required node is on the LEFT side of the list
	if (index < (size / 2)){ 
		current = head;
		for (size_t count = 0; count != index; count++) {
			current = current->next;
		}
	}
	//If the required node is on the RIGHT side of the list
	else
	{
		current = tail;
		for (size_t count = size - 1; count != index; count--)
		{
			current = current -> prev;
		}		
	}
	return current;
}

void DoubleLinkedList::pushBack(DoubleLinkedList anotherList)
{
	tail->next = anotherList.head;
	anotherList.head->prev = tail;
}