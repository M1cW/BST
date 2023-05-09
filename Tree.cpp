#include "Tree.h"

BSTree::BSTree()
{
    this->_root = nullptr;
}
//-----------------------------------------------------------------------------
void BSTree::print(Node *currNode) const
{
    if (currNode == nullptr) // if non-existance node
    {
        std::cout << "-";
    }
    else if (currNode->isLeaf() == true) // if leaf node
    {
        std::cout << currNode->_data;
    }
    else // if non-leaf node
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
    if (this->_root == nullptr) // if the tree is an empty tree
    {
        std::cout << "-"
                  << "\n";
    }
    else // not an empty tree, call helper
    {
        this->print(this->_root);
        std::cout << "\n";
    }
}
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
int BSTree::size() const
{
    if (this->_root == nullptr) // if it's an empty tree, the size would be 0
    {
        return 0;
    }
    else // if not empty, call helper
    {
        return this->size(this->_root);
    }
}
int BSTree::size(Node *currNode) const
{
    if (currNode == nullptr) // if it's a non-existance node
    {
        return 0;
    }
    if (currNode->isLeaf() == true) // size of a leaf node would be 1
    {
        return 1;
    }
    return 1 + this->size(currNode->_left) + this->size(currNode->_right); // return 1(the node itself)+size of left subtree+size of right subtree
}
//-----------------------------------------------------------------------------
void BSTree::remove(int value, Node *currNode, Node *parentNode)
{
    if (currNode == nullptr)
    {
        return;
    }

    if (currNode->_data == value)
    {
        if (currNode->isLeaf())
        {
            if (currNode == parentNode)
            {
                delete currNode;
                this->_root = nullptr;
            }
            else if (parentNode->_left == currNode)
            {
                delete currNode;
                parentNode->_left = nullptr;
            }
            else
            {
                delete currNode;
                parentNode->_right = nullptr;
            }
        }
        else if (currNode->isFull())
        {
            Node *largestLeft = currNode->_left;
            while (largestLeft->_right != nullptr)
            {
                largestLeft = largestLeft->_right;
            }
            currNode->_data = largestLeft->_data;
            remove(largestLeft->_data, currNode->_left, currNode);
        }
        else
        {
            Node *childNode;
            if (currNode->_left == nullptr)
            {
                childNode = currNode->_right;
            }
            else
            {
                childNode = currNode->_left;
            }
            if (currNode == parentNode)
            {
                delete currNode;
                this->_root = childNode;
            }
            else if (parentNode->_left == currNode)
            {
                delete currNode;
                parentNode->_left = childNode;
            }
            else
            {
                delete currNode;
                parentNode->_right = childNode;
            }
        }
    }
    else if (value > currNode->_data)
    {
        this->remove(value, currNode->_right, currNode);
    }
    else
    {
        this->remove(value, currNode->_left, currNode);
    }
}

void BSTree::remove(int value)
{
    if (this->_root == nullptr)
    {
        throw std::invalid_argument("Can't remove node from an empty tree.");
    }
    else
    {
        remove(value, this->_root, this->_root);
    }
}