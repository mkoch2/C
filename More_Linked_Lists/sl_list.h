#ifndef __SL_LIST_H__
#define __SL_LIST_H__
/* More Linked Lists */

/* A node in a singly-linked list that stores values of type int. */

typedef struct intnode
{
    int value;
    struct intnode *next;
} intnode_t;

/* Functions*/

intnode_t *intnode_construct(int value, intnode_t *next);
intnode_t *push(intnode_t *head, int value);
int length(intnode_t *head);
void print_list(intnode_t *head);

/* Functions defined */

intnode_t *add(intnode_t *head, int elem, int index);
void every_other(intnode_t *head);
int count_in_sll(intnode_t *head, int target);
int last_in_sll(intnode_t *head);

#endif