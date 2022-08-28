/* 
Binary search tree (BST) is a binary tree where the value of each node is larger or equal to the values iA three-node binary tree.n all the nodes in that node's left subtree and smaller than the values in all the nodes in that node's right subtree.

Write a function that, efficiently with respect to time used, returns 1 if a given binary search tree contains a given value, else 0.

For example, for the following tree:

    n1 (Value: 1, Left: null, Right: null)
    n2 (Value: 2, Left: n1, Right: n3)
    n3 (Value: 3, Left: null, Right: null)

Call to contains(&n2, 3) should return 1 since a tree with root at n2 contains number 3.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

int contains(const Node *root, int value)
{
    if (root) {
        if (root->value == value)
            return 1;
        else if (root->value >= value)
            return contains(root->left, value);
        return contains(root->right, value);
    }

    return 0;
}

#ifndef RunTests
int main()
{
    Node n1 = {.value=1, .left=NULL, .right=NULL};
    Node n3 = {.value=3, .left=NULL, .right=NULL};
    Node n2 = {.value=2, .left=&n1, .right=&n3};
    Node n5 = {.value=5, .left=NULL, .right=NULL};
    Node n4 = {.value=4, .left=&n2, .right=&n5};
    Node n7 = {.value=7, .left=NULL, .right=NULL};
    Node n9 = {.value=9, .left=NULL, .right=NULL};
    Node n8 = {.value=8, .left=&n7, .right=&n9};
    Node n6 = {.value=6, .left=&n4, .right=&n8};

    printf("%d\n", contains(&n6, 10));
    return 0;
}
#endif