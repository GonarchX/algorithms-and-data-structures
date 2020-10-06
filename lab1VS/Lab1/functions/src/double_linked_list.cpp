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
		Node* current = tail->prev;
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
		Node* current = head->next;
		current->prev = nullptr;
		delete head;
		head = current;
	}
	size--;
}

void   DoubleLinkedList::insert(const int data, const size_t index) //  insert element before element at index
{
	Node* current = findNode(index);

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
	Node* current = findNode(index);
	return current->data;
}

void   DoubleLinkedList::remove(const size_t index) //  deleting an element by index
{
	Node* current = findNode(index);

	if (size == 1) {
		delete current;
		head = nullptr;
		tail = nullptr;
		size--;
	}
	else if (current == head) {
		popFront();
	}
	else if (current == tail) {
		popBack();
	}
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		size--;
	}
}

size_t DoubleLinkedList::getSize() const { return size; } //  getting list size

void   DoubleLinkedList::printToConsole()const //  output of list items to the console
{
	if (!size) {
		cout << "List is empty";
		return;
	}
	Node* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
}

void   DoubleLinkedList::clear() //  removing all list items
{
	if (size == 0) return;
	while (size != 0) {
		popBack();
	}
}

void   DoubleLinkedList::set(const int data, const size_t index) //  replacing the element by index with the passed element
{
	Node* current = findNode(index);
	current->data = data;
}

bool   DoubleLinkedList::isEmpty() const //  checking if the list is empty
{
	if (!getSize()) return true;
	else return false;
}

DoubleLinkedList::Node* DoubleLinkedList::findNode(const size_t index) //Finding the desired node
{
	if (index >= size) throw out_of_range("Index is greater than list size");
	Node* current;

	//If the required node is on the LEFT side of the list, we will start search from head
	if (index < (size / 2)) {
		current = head;
		for (size_t count = 0; count != index; count++) {
			current = current->next;
		}
	}
	//If the required node is on the RIGHT side of the list, we will start search from tail
	else
	{
		current = tail;
		for (size_t count = size - 1; count != index; count--)
		{
			current = current->prev;
		}
	}
	return current;
}

void DoubleLinkedList::pushBack(DoubleLinkedList& connectedList)
{
	if (connectedList.size == 0) return;
	//Connecting head of connected list with tail of our list
	tail->next = connectedList.head;
	connectedList.head->prev = tail;

	//Set tail of connected list like tail of our list 
	tail = connectedList.tail;
	size += connectedList.size;

	//Remove info about connected list
	connectedList.head = nullptr;
	connectedList.tail = nullptr;
	connectedList.size = 0;
}