#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <iostream>

class BSTree
{
private:
    Node *_root;

    void print(Node *) const;         // private helper for print
    void insert(int, Node *&);        // private helper for insert
    int size(Node *) const;           // private helper for size
    void remove(int, Node *, Node *); // private helper for remove
    int height(Node *) const;

    void delete_postOrder(Node *);
    void insert_preOrder(Node *, Node *&);

public:
    BSTree();  // default constructor
    ~BSTree(); // default destructor
    BSTree(const BSTree &);

    void print() const;     // print the whole tree, with the given format
    void insert(int value); // insert a value to the tree
    int size() const;       // get the size of the tree
    void remove(int value); // remove a value from the tree
    int height() const;
};

#endif