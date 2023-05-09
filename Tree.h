#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <stdexcept>
#include <iostream>
class BSTree
{
private:
    Node *_root;
    void insert(int, Node *&);
    void print(Node *) const;

public:
    BSTree(); // default constructor
    void print() const;
    void insert(int value);
};

#endif