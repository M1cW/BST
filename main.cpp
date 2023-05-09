#include "Tree.h"

int main()
{
    BSTree tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(11);
    tree.print();
    std::cout << "size of the tree is " << tree.size() << "\n";
    tree.insert(1);
    tree.print();
    std::cout << "size of the tree is " << tree.size() << "\n";
    return 0;
}