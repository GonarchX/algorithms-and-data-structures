#pragma once
#include <iostream>
#include <stdexcept>
#include "iterator.hpp"

class BinSearchTree
{
private:
    class Node
    {
    public:
        int   data;
        Node *left;
        Node *right;
        Node *parent;
        
        Node(int data, Node* parent = nullptr, 
            Node* left = nullptr, Node* right = nullptr)
        {
            this->data   = data;
            this->parent = parent;
            this->left   = left;
            this->right  = right;
        };
    };

    Node*  root;
    size_t depth;
    friend class Stack;
    friend class Queue;
public:
    BinSearchTree()
    {
        root  = nullptr;
        depth = 0;
    }
    
    Iterator *create_dft_iterator(); // creating an iterator (depth-first traverse)    
    
    //Iterator for BinSearchTree with depth-first traverse method
    class DFT_Iterator: public Iterator{
    private:
        class Stack
        {
        private:
            class Node
            {
            public:
                BinSearchTree::Node *data;
                Node *prev;
                Node *next;
                
                Node(BinSearchTree::Node *data, Node *prev = nullptr, Node *next = nullptr)
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
            Stack()
            {
                head = nullptr;
                tail = nullptr;
                size = 0;
            }
            
            //Work with Stack

            void push(BinSearchTree::Node*); //adding to the end of the list
            
            BinSearchTree::Node *pop(); //  remove the last element and return his value
            
            size_t getSize() const; //  getting list size

            bool isEmpty() const; //  checking if the list is empty
        };
        
        Stack stack;
        Node *current;
    public:
        DFT_Iterator(Node *start)
        {
            current = start;
            stack.push(current); // Create an empty stack and push root to it 
        };
        int next() override;
	    bool has_next() override;
    };

    //Iterator for BinSearchTree with breadth-first traverse method
    
    Iterator *create_bft_iterator(); // creating an iterator (breadth-first traverse)

    class BFT_Iterator: public Iterator{
    private:
        class Queue
        {
        private:
            class Node
            {
            public:
                BinSearchTree::Node *data;
                Node *prev;
                Node *next;
                
                Node(BinSearchTree::Node *data, Node *prev = nullptr, Node *next = nullptr)
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
            Queue()
            {
                head = nullptr;
                tail = nullptr;
                size = 0;
            }
            
            //Work with Queue

            void push(BinSearchTree::Node*); //adding to the start of the list
            
            BinSearchTree::Node *pop(); //  remove the last element and return his value

            size_t getSize() const; //  getting list size

            bool isEmpty() const; //  checking if the list is empty
        };
        
        Queue queue;
        Node *current;
    public:
        BFT_Iterator(Node *start)
        {
            current = start;
            queue.push(current); // Create an empty queue and push root to it 
        };
        int next() override;
	    bool has_next() override;
    };
   
    bool contains(const int); // search for an element in the tree by key
    
    void insert(const int); // adding an element to the tree by key

    Node *find(const int); // return element int the tree by key 

    void remove(const int); // deleting a tree element by key     
};