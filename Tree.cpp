#include "Tree.h"

BSTree::BSTree()
{
    this->_root = nullptr;
}
void BSTree::print(Node *currNode) const
{
    if (currNode == nullptr)
    {
        std::cout << "-";
    }
    else if (currNode->_left == nullptr && currNode->_right == nullptr)
    {
        std::cout << currNode->_data;
    }
    else
    {
        std::cout << "(";
        this->print(currNode->_left);
        std::cout << " ";
        std::cout << currNode->_data;
        std::cout << " ";
        this->print(currNode->_right);
        std::cout << ")";
    }
}

void BSTree::print() const
{
    if (this->_root == nullptr)
    {
        std::cout << "-";
    }
    else
    {
        this->print(this->_root);
    }
}
void BSTree::insert(int value, Node *&currNode)
{
    if (currNode == nullptr)
    {
        Node *newNode = new Node(value);
        currNode = newNode;
        return;
    }
    else
    {
        if (value == currNode->_data)
        {
            throw std::invalid_argument("inserting an element that already exists in the binary search tree: no duplicate value allowed");
        }
        if (value < currNode->_data)
        {
            this->insert(value, currNode->_left);
        }
        if (value > currNode->_data)
        {
            this->insert(value, currNode->_right);
        }
    }
}
void BSTree::insert(int value)
{
    if (this->_root == nullptr)
    {
        Node *newNode = new Node(value);
        this->_root = newNode;
        return;
    }
    else
    {
        this->insert(value, this->_root);
    }
}
