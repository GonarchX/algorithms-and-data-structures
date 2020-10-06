#pragma once
#include <iostream>

#pragma once

class DoubleLinkedList
{
private:
    class Node
    {
    public:
        int   data;
        Node *prev;
        Node *next;
        
        Node(int data, Node * prev = nullptr, Node * next = nullptr)
        {
            this->data = data;
            this->prev = prev;
            this->next = next;
        };
    };

    Node  *head;
    Node  *tail;
    size_t size;
public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~DoubleLinkedList()
    {
        clear();
    }
    
    //Work with double linked list

    void pushBack(const int); //adding to the end of the list
    
    void pushFront(const int); //  adding to the beginning of the list
    
    void popBack(); //  remove the last element

    void popFront(); //  removing the first element

    void insert(const int, const size_t); //  adding an element at index 

    int at(const size_t); //  getting an element by index

    void remove(const size_t); //  deleting an element by index
    
    size_t getSize() const;//  getting list size
    
    void printToConsole()const; //  output of list items to the console

    void clear(); //  removing all list items

    void set(const int, const size_t); //  replacing the element by index with the passed element
    
    bool isEmpty() const; //  checking if the list is empty

    Node *findNode(const size_t index); //Finding the required node in the list

    void pushBack(DoubleLinkedList &List); // Push another list to the end
};