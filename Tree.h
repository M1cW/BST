#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <stdexcept>
#include <iostream>
class BSTree
{
private:
    Node *_root;

    void print(Node *) const;
    void insert(int, Node *&);
    int size(Node *) const;
    void remove(int, Node *);

public:
    BSTree(); // default constructor
    void print() const;
    void insert(int value);
    int size() const;
    void remove(int value);
};

#endif