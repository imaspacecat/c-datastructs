#pragma once

struct Node
{
    struct Node *next;
    struct Node *prev;
    char* data;
};

struct DoublyLinkedList
{
    struct Node *first;
    struct Node *last;
};