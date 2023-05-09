#ifndef NODE_H
#define NODE_H

struct Node
{
    int _data;
    Node *_left;
    Node *_right;
    Node(int value)
    {
        this->_data = value;
        this->_left = nullptr;
        this->_right = nullptr;
    }

    bool isLeaf() const
    {
        if (this->_left == nullptr && this->_right == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif