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
// currNode is like the position that the node should be in, therefore pass by reference(we want to change the tree)
{
    if (currNode == nullptr) // find the space
    {
        Node *newNode = new Node(value);
        currNode = newNode;
        return;
    }
    else
    {
        if (value == currNode->_data) // BST doesn't allow duplicate value
        {
            std::cout << "inserting an element that already exists in the binary search tree: no duplicate value allowed"
                      << "\n";
            return;
        }
        if (value < currNode->_data) // if the value is smaller than the current posiiton, then it has to be in the left subtree
        {
            this->insert(value, currNode->_left);
        }
        if (value > currNode->_data) // similarily.....
        {
            this->insert(value, currNode->_right);
        }
    }
}
void BSTree::insert(int value)
{
    if (this->_root == nullptr) // if the tree is an empty tree
    {
        Node *newNode = new Node(value); // directly add the tree
        this->_root = newNode;           // set the root to the new node
        return;
    }
    else
    {
        this->insert(value, this->_root); // if not empty, call helper
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
// currNode is the current position we are on, parent Node is a pointer to the parent node of the current position (current node)
{
    if (currNode == nullptr) // if we didn't find anything
    {
        std::cout << "The element is not found in the tree"
                  << "\n";
        return;
    }

    if (currNode->_data == value) // if we find the node with the value we want to delete
    {
        if (currNode->isLeaf())
        {
            // case 1: the node is a leaf node
            if (currNode == parentNode) // 1.1 the node is also the root (a tree with only a node)
            {
                delete currNode;
                this->_root = nullptr;
            }
            else if (parentNode->_left == currNode) // 1.2 the leaf node is the left node of it's parent
            {
                delete currNode;
                parentNode->_left = nullptr;
            }
            else // 1.3 ~right~
            {
                delete currNode;
                parentNode->_right = nullptr;
            }
        }
        else if (currNode->isFull())
        {
            // case 2: the node is a full node
            // we do not need to consider when it's deleting the root since it's always deleting a leaf node at the end
            Node *largestLeft = currNode->_left; // we need to find the largest node in the left subtree
            while (largestLeft->_right != nullptr)
            {
                largestLeft = largestLeft->_right;
            }
            currNode->_data = largestLeft->_data;                  // set the data to the largest node in the left subtree
            remove(largestLeft->_data, currNode->_left, currNode); // remove the leaf node by recursion
        }
        else
        {
            // case 3: the node has only one child
            Node *childNode; // we need to first have a pointer to it's child
            if (currNode->_left == nullptr)
            {
                childNode = currNode->_right;
            }
            else
            {
                childNode = currNode->_left;
            }

            if (currNode == parentNode) // 3.1 if the node is the root
            {
                delete currNode;
                this->_root = childNode;
            }
            // 3.2 & 3.3 adjust the parent's pointer to the child based on whether the node we want to delete is the parent node's left or right child
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
    else if (value > currNode->_data) // recursion step, similar to insert
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
    if (this->_root == nullptr) // if it is an empty tree
    {
        std::cout << "Can't remove value from an empty tree"
                  << "\n";
        return;
    }
    else
    {
        remove(value, this->_root, this->_root); // if not empty, call helper
    }
}