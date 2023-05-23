#pragma once

struct Node {
   struct Node* next;
   struct Node* prev;
   int data;
};


struct DoublyLinkedList {
   struct Node* first;
   struct Node* last;
};