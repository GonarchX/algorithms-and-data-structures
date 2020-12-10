#pragma once
#include <string>

#include "iterator.hpp"

class List
{
private:
    class Node
    {
    public:
        std::string data;
        Node *prev;
        Node *next;
        
        Node(std::string data, Node *prev = nullptr, Node *next = nullptr)
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
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //Work with iterator
    Iterator *create_iterator() const;

    class listIterator: public Iterator{
        private:
            Node *current;
        public:            
            listIterator(Node *start) : current(start){}
            std::string getCurrent() override;
            void next() override;
            bool has_next() override;
    };

    void push(std::string); //adding to the end of the list
    
    std::string pop(); //  remove the last element and return his value
    
    size_t getSize() const; //  getting list size

    bool isEmpty() const; //  checking if the list is empty

    std::string getHead() const;

    std::string getTail() const;

    void print() const;

    friend List parse(std::string &str);
};