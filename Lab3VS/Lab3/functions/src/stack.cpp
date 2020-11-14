#include "../lib/binary_search_tree.hpp"

//adding to the end of the list
void BinSearchTree::DFT_Iterator::Stack::push(BinSearchTree::Node *data)
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
BinSearchTree::Node *BinSearchTree::DFT_Iterator::Stack::pop()
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
size_t BinSearchTree::DFT_Iterator::Stack::getSize() const{return size;}

//  checking if the list is empty
bool BinSearchTree::DFT_Iterator::Stack::isEmpty() const
{
    return !getSize();    
}