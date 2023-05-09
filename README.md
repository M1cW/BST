# BST

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
((a b c) d (- e f))
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
