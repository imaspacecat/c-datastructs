#include <stdio.h>
#include "C:\Users\libra\code\c\testing\DoublyLinkedList\linked.h"


// struct Node {
//    struct Node* next;
//    struct Node* prev;
//    int data;
// };


// struct DoublyLinkedList {
//    struct Node first;
//    struct Node last;
// };

void insert_node_after(struct DoublyLinkedList* l, struct Node* node, struct Node* new) {
   new->prev = node;
   if (node->next == NULL) {
      printf("here\n");
      new->next = NULL;
      l->last = new;
   } else {
      new->next = node->next;
      node->next->prev = new;
   }
   node->next = new;
   if(node->next == NULL) {
      printf("its null lol\n");
   }
}


// void insert_node_before(struct DoublyLinkedList l, struct Node node, struct Node new) {

// }

void print_linked_list(struct DoublyLinkedList l) {
   struct Node* node = l.first;
   int count = 1;
   while (1) {
      printf("%d: %d\n", count, node->data);
      printf("%d: %p\n", count++, node->next);
      
      if (node == l.last) {
         printf("i breaked\n");
         break;
      }
      
      node = node->next;
      
      
      if(&node == NULL) {
         printf("its null lol\n");
      }
   }
}

int main() {

   struct Node first = {NULL, NULL, 10};
   struct DoublyLinkedList l = {&first, NULL};
   struct Node new = {NULL, NULL, 2};
   
   insert_node_after(&l, l.first, &new);


   print_linked_list(l);
   


   return 0;
}