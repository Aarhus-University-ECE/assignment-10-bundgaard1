#include "linked_list.h"

#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

/* functions to create lists */
node *make_node(int v, node *q) {
    node *p = malloc(sizeof(node));
    p->value = v;
    p->next = q;
    return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
    node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}

/* print list to console */
void print_list(node *p) {
    // Add your code for exercise 1

    if (p == NULL) return;     // An empty list, just return
    printf("%d, ", p->value);  // Print value
    print_list(p->next);       // Goto next node in list
}

int sum_squares(node *p) {
    // Add your code for excercise 2
    // You can find the tests in tests.cpp

    if (p == NULL) return 0;  // Base case: End of list
    // returns the current value squared and the sum of the remaining list
    return p->value * p->value + sum_squares(p->next);
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) {
    // Add your code for excercise 3

    // If the node is empty, return a NULL node
    if (p == NULL) return (node *)NULL;

    // Else return a new node,
    // With value of the current value through the unary function
    // And points to the next node which is passed through the map function
    return make_node(f(p->value), map(p->next, f));
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
