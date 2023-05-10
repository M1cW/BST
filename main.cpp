#include "Tree.h"

int main()
{
    BSTree tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(11);
    tree.remove(12);
    tree.print();
    return 0;
}