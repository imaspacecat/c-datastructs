#include <stdio.h>
#include "C:\Users\libra\code\c\testing\DoublyLinkedList\linked.h"

void insert_node_after(struct DoublyLinkedList *l, struct Node *node, struct Node *new)
{
    new->prev = node;
    if (node->next == NULL)
    {
        new->next = NULL;
        l->last = new;
    }
    else
    {
        new->next = node->next;
        node->next->prev = new;
    }
    node->next = new;
}

// void insert_node_before(struct DoublyLinkedList l, struct Node node, struct Node new) {

// }

void print_linked_list(struct DoublyLinkedList l)
{
    struct Node *node = l.first;
    int count = 1;

    while (1)
    {
        printf("%d: %s\n", count, node->data);
        printf("%d: %p\n", count++, node->next);

        if (node == l.last)
        {
            break;
        }

        node = node->next;
    }
}

void free_linked_list(struct DoublyLinkedList *l)
{
    struct Node *node = l->first;

    while (1)
    {
        free(node->data);
        printf("asdsad");

        if (node == l->last)
        {
            break;
        }

        node = node->next;
    }
}

// accept node as a param instead
void init_node_str(struct Node* node) {
    char* s = node->data;
    node->data = (char *) malloc(strlen(s)+1);
    strcpy(node->data, s);
}

int main()
{

    
    struct Node test = {NULL, NULL, "this is a test"};
    init_node_str(&test);


    struct DoublyLinkedList l = {&test, NULL};
    
    struct Node new = {NULL, NULL, "test 2 electric boogaloo"};
    init_node_str(&new);

    insert_node_after(&l, l.first, &new);


    struct Node new2 = {NULL, NULL, "amogus"};
    init_node_str(&new);

    insert_node_after(&l, l.first, &new2);

    print_linked_list(l);

    free_linked_list(&l);

    return 0;
}