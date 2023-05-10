# BST
In this repository, I am implementing a binary search tree for practice, with several common function implementation. 
This tree is not self-balancing. There will be cases when it has poor (O(n)) performance. 
## Tree Notation
A binary tree might look something like this:
```
    8
   / \
  5   10
 / \   \
2   6   11
```
But we need an easy way to print a tree to the console. So we'll define a tree
notation that lets us write a tree structure as a single line. In this notation,
the tree pictured above would look like this:
```
((2 5 6) 8 (- 10 11))
```
More formally:
- The tree notation for a leaf node is simply its value.
- The tree notation for a non-existent node is a hyphen (`-`; ASCII value 45).
- The tree notation for a non-leaf node is:
  - A left parenthesis, followed by
  - the tree notation for its left subtree, followed by
  - a space, followed by
  - the node's value, followed by
  - a space, followed by
  - the tree notation for its right subtree, followed by
  - a right parenthesis.
- The tree notation for an empty tree is `-`.
## Functions implemented
- The default constructor.
- The destructor. 
- The copy constructor.
- `print()` prints the tree in the format given above.
- `insert(value)` inserts the value to the tree if the value is not in the tree. If the value is already inside the tree, the function does nothing to the tree and prints an error line. 
- `size()` returns the size of the tree in an integer.
- `remove(value)` removes the value from the tree if the value is in the tree. If the value is not in the tree or the tree is an empty tree, the function does nothing to the tree and prints an error line. 

