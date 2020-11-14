#include <stdexcept>
#include "../lib/binary_search_tree.hpp"
using namespace std;

// Work with DFT iterator

Iterator *BinSearchTree::create_dft_iterator()
{
    if (!root) throw ("Unable to create an iterator because the tree does not contain any elements!");
	return new DFT_Iterator(root);
}

bool BinSearchTree::DFT_Iterator::has_next() 
{
    return (current != nullptr && !stack.isEmpty());
}

int BinSearchTree::DFT_Iterator::next()
{
    if (!has_next()) throw out_of_range("No more elements");

    // Pop the top item from stack
    BinSearchTree::Node *current = stack.pop();

    // Push right and left children of the popped node to stack 
    if (current->right) 
        stack.push(current->right); 
    if (current->left) 
        stack.push(current->left); 

    return current->data;
}

// Work with BFT iterator

Iterator *BinSearchTree::create_bft_iterator()
{
    if (!root) throw ("Unable to create an iterator because the tree does not contain any elements!");
	return new BFT_Iterator(root);
}

bool BinSearchTree::BFT_Iterator::has_next() 
{
    return (current != nullptr && !queue.isEmpty());
}

int BinSearchTree::BFT_Iterator::next()
{
    if (!has_next()) throw out_of_range("No more elements");

    // Pop the first item from queue and print it
    BinSearchTree::Node *current = queue.pop();

    // Push left and right children of the popped node to queue 
    if (current->left) 
        queue.push(current->left); 
    if (current->right) 
        queue.push(current->right); 
    
    return current->data;
}
// Work with BInary Search Tree

bool BinSearchTree::contains(int const key)
{    
    // Empty tree
    if (!depth) return false;
    else{
        Node *current = root;
        while(true)
        {
            if (key == current->data) return true;
            else if (key > current->data){
                if(current->right == nullptr) return false;
                // Change the current node to its right node
                else current = current->right;
            }
            //key <= current->data
            else{
                if(current->left == nullptr) return false;
                // Change the current node to its left node
                else current = current->left;
            }
        }
    }
}

void BinSearchTree::insert(int const key)
{
    // Empty tree
    if (!depth){
        root = new Node(key);
        depth++;
    }
    else{
        Node *current = root;
        while(true)
        {
            if (key > current->data){
                //If we don't have right node
                    //then we create him
                if(current->right == nullptr){
                    current->right = new Node(key, current);
                    depth++;
                    return;
                }
                // Change the current node to its right node
                else current = current->right;
            }
            //key <= current->data
            else{
                //If we don't have left node
                    //then we create him
                if(current->left ==nullptr){
                    current->left = new Node(key,current);
                    depth++;
                    return;
                }
                // Change the current node to its left node
                else current = current->left;
            }
        }        
    }
}

BinSearchTree::Node *BinSearchTree::find(const int key)
{
    // Empty tree
    if (!depth) return nullptr;
    else{
        Node *current = root;
        while(true)
        {
            if (key == current->data) return current;
            else if (key > current->data){
                if(current->right == nullptr) return nullptr;
                // Change the current node to its right node
                else current = current->right;
            }
            //key <= current->data
            else{
                if(current->left == nullptr) return nullptr;
                // Change the current node to its left node
                else current = current->left;
            }
        }
    }
}

void BinSearchTree::remove(int const key)
{
    Node *current = find(key);
    if(!current) throw ("Tree not contains this key!");

    //If the required Node don't any leafs
    if(current->left == nullptr && current->right == nullptr){
        if (current == root){
            delete current;
            root = nullptr;
        }
        else{
            // If the required Node is the left leaf of its parent
            if(current->data <= current->parent->data) current->parent->left = nullptr;
            // If the required Node is the right leaf of its parent
            else current->parent->right = nullptr;
            delete current;            
        }
        depth--;
    }
    //If the required Node have two leafs
    else if(current->left != nullptr && current->right != nullptr){
        Node *minNode = current->right;        
        // Finding minimal leaf
        while(minNode->left != nullptr){
            minNode = minNode->left;
        }
        current->data = minNode->data;

        // If the minimal Node is the left leaf of its parent
        if(minNode == minNode->parent->right) minNode->parent->right = nullptr;
        // If the minimal Node is the right leaf of its parent
        else minNode->parent->left = nullptr;
        
        delete minNode;
        depth--;
    }
    //If the required Node have only one leaf    
    else{
        if(current->left == nullptr){
            if (current == root){
                root = current->right;
                root->parent = nullptr;
                delete current;
            }
            else{
                current->right->parent = current->parent;
                current->parent->right = current->right;
                delete current;
            }
        }
        else{
            if (current == root){
                root = current->left;
                root->parent = nullptr;
                delete current;
            }
            else{
                current->left->parent = current->parent;
                current->parent->left = current->left;
                delete current; 
            }                       
        }
        depth--;
    }    
}