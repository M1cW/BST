#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <stdexcept>
#include <iostream>

class BSTree
{
private:
    Node *_root;

    void print(Node *) const;         // private helper for print
    void insert(int, Node *&);        // private helper for insert
    int size(Node *) const;           // private helper for size
    void remove(int, Node *, Node *); // private helper for remove

public:
    BSTree(); // default constructor

    void print() const;     // print the whole tree, with the given format
    void insert(int value); // insert a value to the tree
    int size() const;       // get the size of the tree
    void remove(int value); // remove a value from the tree
};

#endif