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

void insert_string_after(struct DoublyLinkedList *l, struct Node *node, char s[])
{
    char *sp = (char *) malloc(sizeof(s));
    struct Node new = {NULL, NULL, *sp};
    insert_node_after(l, node, &new);
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

int main()
{

    struct Node first = {NULL, NULL, "amogus"};
    struct DoublyLinkedList l = {&first, NULL};
    struct Node new = {NULL, NULL, "sus"};

    insert_node_after(&l, l.first, &new);
    struct Node e = {NULL, NULL, "eeeee"};
    insert_node_after(&l, l.last, &e);

    print_linked_list(l);

    return 0;
}