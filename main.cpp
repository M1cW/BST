#include "Tree.h"

int main()
{
    BSTree tree;
    tree.insert(666);
    tree.insert(233);
    tree.insert(3);
    tree.insert(555);
    tree.insert(8);
    tree.insert(10000);
    tree.insert(998);
    tree.insert(2888);
    tree.print();
    std::cout << tree.height() << "\n";
    // BSTree tree2(tree);
    // tree2.print();
    return 0;
}