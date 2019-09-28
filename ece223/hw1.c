/* Homework 1
 * Jacovia Cherry
 * ECE 2230, Fall 2019
 *
 * Write  a C program that creates a singly-linked circular list and performs the folllowing operations:
 *      1. Insert the number 1-10 at the heads of the list
 *      2. Insert the numbers 21-30 at the tail of the list
 *      3. Insert the numbers 11-20 in the middle of the list
 *       4. Remove 5 items at the head of the list
 *       5. Remove 5 items at the tail of the list
 *       6. Print the remaining items on the list
*/
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

/*create lnode */
struct node{
    int info;                   //data held in node
    struct node *link;          //pointer to an lnode
};



int main(void) {

   /*allocate an node*/
   struct node * head, *tail, *newNode, *middle;
   head = NULL;
   tail = NULL;

   /* insert at head of list */
   int i;
   for (i = 10; i > 0; i--) {
      if (head == NULL) {
         head = (struct node *) malloc(sizeof(struct node));
         head->link = NULL;
         tail = head;
         middle = head;
         head->info = i;
      } else {
         newNode = (struct node *) malloc(sizeof(struct node));
         newNode->link = head;
         newNode->info = i;
         head = newNode;
      }
   }

   /*insert at tail of list */
   int j;
   for (j = 21; j < 31; j++) {
      if (tail->link == NULL) {
         newNode = (struct node *) malloc(sizeof(struct node));
         tail->link = newNode;
         newNode->info = j;
         newNode->link = NULL;
         tail = newNode;
      }
   }

   tail->link = head; //make the list circular

   /*insert in middle of list*/
   struct node *rover, *next;
   rover = (struct node *) malloc(sizeof(struct node));
   next = (struct node *) malloc(sizeof(struct node));
   rover = middle;
   next = rover->link;

   int k;
   for (k = 11; k < 21; k++) {
      newNode= (struct node *) malloc(sizeof(struct node));
      middle->link = newNode;
      newNode->info = k;
      newNode->link = next;
      rover = newNode;
      next = rover->link;
      middle = rover;
   }

   /* remove from head of list*/
   struct node *prev, *temp;
   prev = (struct node *) malloc(sizeof(struct node));
   temp = (struct node *) malloc(sizeof(struct node));
   int count;
   for (count = 1; count < 6; count++) {
      if (count == head->info) {
         temp = head;
         head = head->link;
         temp = NULL;
         tail->link = head;
      }
   }

   /*remove from end of list */
   printf(" Tail of list: [%d]\n", tail->info);
   printf(" Beginning of list: [%d]\n", tail->link->info);

   struct node *current;
   current = head;
   for (count = 25; count > 20; count--) {
      while (current->link != tail) {
         current = current->link;
      }
      tail = current;
      tail->link = head;
   }

   /*print list*/
   rover = head;
   do {
     printf(" Final list: [%d]\n", rover->info);
     rover = rover->link;
   } while(rover != head);

   return 0;
}
