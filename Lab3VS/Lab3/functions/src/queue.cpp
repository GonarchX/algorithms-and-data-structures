#include "../lib/binary_search_tree.hpp"

//adding to the end of the list
void BinSearchTree::BFT_Iterator::Queue::push(BinSearchTree::Node *data)
{
    if (isEmpty()) {
		head = new Node(data);
		tail = head;
	}
	else {
		head->prev = new Node(data, nullptr, head);
		head = head->prev;
	}
	size++;
}

//  remove and return the last element
BinSearchTree::Node *BinSearchTree::BFT_Iterator::Queue::pop()
{
    if (isEmpty()) return nullptr;

	BinSearchTree::Node *temp;

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
size_t BinSearchTree::BFT_Iterator::Queue::getSize() const{return size;}

//  checking if the list is empty
bool BinSearchTree::BFT_Iterator::Queue::isEmpty() const
{
    return !getSize();    
}