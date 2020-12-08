#include <iostream>
#include "../lib/stack.hpp"

using namespace std;

//adding to the end of the list
void Stack::push(string data)
{
    if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->next = new Node(data, tail);
		tail = tail->next;
	}
	size++;
}

//  remove and return the last element
string Stack::pop()
{
    if (isEmpty()) return nullptr;

	string temp;

	if (size == 1) {
		temp = head->data;
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else{
		temp = tail->data;
		Node *current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
	return temp;
}

//  getting list size
size_t Stack::getSize() const{return size;}

//  checking if the list is empty
bool Stack::isEmpty() const
{
    return !getSize();    
}

void Stack::print() const
{
	Node *current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

string Stack::getHead() const {return head->data;}

string Stack::getTail() const {return tail->data;}

// Work with stack iterator

Iterator *Stack::create_iterator() const
{
    if (!head) throw ("Unable to create an iterator because the stack does not contain any elements!");
	return new stackIterator(head);
}

string Stack::stackIterator::getCurrent() {return current->data;}

void Stack::stackIterator::next()
{
    if (!has_next()) throw out_of_range("No more elements");
	string temp = current->data;
	current = current->next;
}

bool Stack::stackIterator::has_next() 
{
    return (current != nullptr);
}