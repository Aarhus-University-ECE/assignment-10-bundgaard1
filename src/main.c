#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#include "linked_list.h"

void printTree(struct tree_node *t, int depth) {
    if (t->item == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("-");
    }
    printf("|%d\n", t->item);

    printTree(t->left, depth + 1);
    printTree(t->right, depth + 1);

    return;
}

// File for sandboxing and trying out code
int main(int argc, char **argv) {
    // Add your code
    struct tree_node *root;

    root = Initialize(root);
    root = Insert(1, root);
    root = Insert(1, root);
    root = Insert(2, root);
    root = Insert(2, root);
    root = Insert(1, root);

    printTree(root, 0);

    root = Remove(1, root);

    printTree(root, 0);

    return 0;
}