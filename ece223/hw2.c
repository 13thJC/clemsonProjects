/* Homework 2
 * Jacovia Cherry
 * ECE 2230, Fall 2019
 *
 * Write  a C program with a stack and a queue.
 *
 *      1. Using a for loop, insert(push) the numbers 1-20 into the stack.
 *      2. Using a while loop, remove(pop) the numbers one at a time and insert then into the queue.
 *      3. Finally, remove the numbers from the queue with another while loop and print them.
 *
 * Even though you know how many numbers you are using, your while loops should check for
 * empty stack or queue, rather than stackCounting how many numbers to remove.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* A structure to represent a stack */
typedef struct StackNode {
    int info;
    struct StackNode* link;
} Stack;

Stack *top, *newTop, *temp;

/* a structure to represent a queue */
typedef struct QueueNode {
   int info;
   struct QueueNode *link;
} Queue;

Queue  *front, *rear, *hold, *newFront;

int stackCount , qCount = 0;
/*function prototypes */
int topElement();
void displayStack();
void push(int data);
void pop();
void isStackEmpty();
void create();
void qSize();
void enQ();
void displayQ();
void deQ();

/*function to push info onto the stack */
void push( int data)
{
      temp = (Stack *)malloc(sizeof(Stack));
      temp->info = data;
      temp->link = top;
      top = temp;
      stackCount++;
}

/*function to create the Queue*/
void create()
{
   front = rear = NULL;
}

/*returns size of queue*/
void qSize()
{
   printf("\nQueue has %d elements.", qCount);
}

/*function to enqueue an item from stack to queue */
void enQ( int data )
{
   //empty Queue
   if (rear == NULL)
   {
      rear = (Queue *)malloc(sizeof(Queue));
      rear->link = NULL;
      rear->info = data;
      front = rear;
   } else {
      hold = (Queue *)malloc(sizeof(Queue));
      rear->link = hold;
      hold->info = data;
      hold->link = NULL;
      rear = hold;
   }
   qCount++;         //update size of queue
}
/*function to pop element from stack onto queue*/
void pop_StackToQueue ( )
{
   newTop = top;
   if (newTop == NULL) {

      printf("\nError: Cannot pop from empty stack!");
      return;

   } else {

      newTop = newTop->link; //move to next element in the stack
      //printf("\nValue popped from stack : %d.",  top->info); //Stack elemernt at the top of stack
      enQ(top->info); //insert element into queue
      //qSize();
      free(top); //remove element from top of stack
      top = newTop; //make old second highest element in stack the new highest element
      stackCount --; //
   }
}


/* function to display what is on top of the stack */
int topElement( )
{
   return (top->info);
}

/*function to check if stack is empty of not*/
void isStackEmpty( )
{
   if (top == NULL) {
      printf("\nStack is empty." );
   } else {
      printf("\nStack has %d elements.", stackCount);
   }
}

/*function to check if queue is empty of not*/
void isQueueEmpty( )
{
   if ((front == NULL) && (rear == NULL)) {
      printf("\nQueue is empty." );
   }
   else if ((newFront == NULL) && (rear == NULL)) {
      printf("\nQueue is empty." );
   } else {
      printf("\nQueue is not empty." );
      qSize();
   }
}

/* Display stack elements */
void displayStack()
{
       newTop = top;
       if (newTop == NULL)  {
           printf("\nStack is empty.\n");
           return;
       }
       printf("\n\nStack:|" );
       while (newTop != NULL)  {
           printf(" %d |", newTop->info);
           newTop = newTop->link;
       }
}

/* Display queue elements */
void displayQ()
{
      newFront = front;

      /*empty queue*/
      if ((newFront == NULL) && (rear == NULL) && (front == NULL)) {
         printf("\nQueue is empty" );
         return;
      }

      /*more than one element in queue*/
      printf("Queue:" );
      while (newFront != rear) {
         printf("| %d ", newFront->info);
         newFront = newFront->link;
      }

      /*only one element in Q*/
      if (newFront == rear) {
         printf("| %d |", newFront->info);
      }
}

void deQ()
{
   newFront = front;
   if (newFront == NULL) {
      printf("\nError: Cannot remove from empty queue!" );
      return;

   } else if (newFront->link != NULL) {

      newFront = newFront->link;
      printf("\nValue deQueued: %d.",  front->info);  //element at front of Queue
      free(front);
      front = newFront;

   } else {
      printf("\nValue deQueued: %d.",  front->info);   //element at front of Queue
      free(front);
      front = NULL;
      rear = NULL;
   }
   qCount--;
}

int main() {

   /* for loop to pop 1-20 onto stack */
   int i;
   for (i = 1; i < 21; i++) {
      push (i);
   }

   displayStack();       // check to see if numbers 1-20 correctly popped onto stack
   isStackEmpty();
   isQueueEmpty();

   create();               //create Queue

   /*pop numbers from stack onto the queue*/
   while (stackCount != 0) {
      pop_StackToQueue();
   }

   isStackEmpty();          //check to make sure stack is empty
   printf("\n");
   displayQ();                //check to see if numbers were popped from stack onto queue

   /*remove elements from queue*/
   while(qCount != 0) {
      deQ();
   }

   isQueueEmpty();           //check to make sure queue is empty
   printf("\n\n\n" );

   return 0;
}
