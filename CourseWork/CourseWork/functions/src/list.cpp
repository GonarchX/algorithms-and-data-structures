#include <iostream>
#include "../lib/list.hpp"

using namespace std;

//adding to the end of the list
void List::push(string data)
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
string List::pop()
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
size_t List::getSize() const{return size;}

//  checking if the list is empty
bool List::isEmpty() const
{
    return !getSize();    
}

void List::print() const
{
	Node *current = head;
	while(current)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

string List::getHead() const {return head->data;}

string List::getTail() const {return tail->data;}

// Work with list iterator

Iterator *List::create_iterator() const
{
    if (!head) throw ("Unable to create an iterator because the list does not contain any elements!");
	return new listIterator(head);
}

string List::listIterator::getCurrent() {return current->data;}

void List::listIterator::next()
{
    if (!has_next()) throw out_of_range("No more elements");
	string temp = current->data;
	current = current->next;
}

bool List::listIterator::has_next() 
{
    return (current != nullptr);
}