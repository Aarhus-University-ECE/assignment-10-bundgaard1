#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
    // Insert item x into the tree t

    // If empty make the root x
    // This is also if we have reached a leaf node
    if (Empty(t)) {
        t->item = x;
        // Make empty left and right node
        struct tree_node *left;
        t->left = Initialize(left);
        struct tree_node *right;
        t->right = Initialize(left);
    }

    else if (t->item == x) {
        // Found an equal node to the one to be inserted
        struct tree_node *new;
        new = Initialize(new);  // Make new empty node
        new->item = x;
        new->left = t->left;            // Make it left point at roots left
        new->right = Initialize(NULL);  // And right to an empty node
        t->left = new;  // It inserted a new node between t and t.left

    } else if (t->item > x) {
        // search the left subtree for a place to insert x
        Insert(x, t->left);

    } else if (t->item < x) {
        // search the right subtree for a place to insert x
        Insert(x, t->right);
    }

    return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
    // Remove one item "x" from the tree t

    if (!Contains(x, t)) return t;  // Make sure x is in the tree

    // Found the cell - Remove cell
    if (t->item == x) {
        // Leaf node - no children
        // Both left and right is empty, and item is only field not to be NULL
        // This makes an "Empty" node
        if (Empty(t->left) && Empty(t->right)) {
            t->item = NULL;
        }

        // 1 child
        else if ((Empty(t->left)) != (Empty(t->right))) {
            // It "shuffles" the nodes down,
            if (!Empty(t->left)) {
                t->item = t->left->item;   // Make same value as next
                Remove(t->item, t->left);  // Remove the next node
            } else {
                t->item = t->right->item;
                Remove(t->item, t->right);
            }
        }

        // 2 children
        else {
            // Here we find the smallest node which is bigger than x, search
            // right, and the left most node, to swap with t
            struct tree_node *temp;
            temp = Initialize(temp);
            temp = t->right;  // Search right
            // Keep going left to find the smallest
            while (temp->left->item != NULL) {
                temp = temp->left;
            }

            t->item = temp->item;  // "Swap" value

            // Remove the node which were made the new root
            Remove(temp->item, t->right);
        }

    } else if (t->item > x) {
        // If x is smaller -> search left tree
        Remove(x, t->left);
    } else if (t->item < x) {
        // If x is bigger -> search right tree
        Remove(x, t->right);
    }

    return t;
}

int Contains(int x, struct tree_node *t) {
    // Return true if the tree t contains item x. Return false otherwise.
    if (Empty(t)) {
        // If t is empty there is nothing to be found
        return 0;
    } else if (t->item == x) {
        // If it is found return true
        return 1;
    } else if (t->item > x && t->left != NULL) {
        // Search left subtree, if the target value is less than t.item.
        // Recursivly call the algorithm for the left subtree
        return Contains(x, t->left);
    } else if (t->item < x && t->right != NULL) {
        // Search right subtree, if the target value is greater than t.item.
        // Recursivly call the algorithm for the right subtree
        return Contains(x, t->right);
    } else {
        return 0;
    }
}

struct tree_node *Initialize(struct tree_node *t) {
    // Create an empty tree
    t = (struct tree_node *)malloc(sizeof(struct tree_node));
    // Initialize with all the fields set to NULL
    t->left = NULL;
    t->right = NULL;
    t->item = NULL;
    return t;
}

int Empty(struct tree_node *t) {
    // Test if empty
    // Empty if the nodes item is NULL
    if (t->item == NULL)
        return 1;
    else
        return 0;
}

int Full(struct tree_node *t) {
    // Test if full
    // What does this mean??
    return 0;
}
