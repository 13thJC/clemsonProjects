/* -------------------- */
/* queue.c             */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*create a linked list*/
typedef struct node {
	qdata data;
	struct node *next;
} node;

/*	create queue which pointers to the first node in the queue, the last
	and the amount of items in the queue*/
typedef struct Queue {
	int count;
	node *front;
	node *rear;
} queue;

/*function prototypes */
queue* initialize();
int isempty(queue *q);
void enqueue(queue *q, qdata data);
int front(queue *q);
void dequeue(queue *q);

/*	initialize queue by setting count to 0
	and pointing the head and tail to NULL */
queue* initialize() {
	queue  *q = malloc(sizeof(q));
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
	return (q);
}
/* check to see if queue is empty */
int isempty(queue *q) {
	if (q->front == NULL) {
       //printf("Queue is empty.\n");
	   return 1;
   } else {
	  // printf("Queue is not empty.\n");
	   return 0;
   }
}
/* function to add elements to the queue from the rear */
void enqueue(queue *q, qdata data) {
	node *temp; 				// create a new node to add to the queue
	temp = (node *)malloc(sizeof(node));	//request memory for the node
	temp->data = data;
	temp->next = NULL;
	// if queue not empty, add to end of queue
	if (isempty(q) == 0) {
		q->rear->next = temp;
		q->rear = temp;
	// if empty, insert first node into queue
	} else {
		q->front = q->rear = temp;
	}
	q->count++;							// update size of queue
}
/* function to display what is at the front of the queue*/
int front(queue *q) {
	return (q->front->data);
}
/* function to delete the front node and return its value */
void dequeue(queue *q) {

	if (isempty(q) == 1) {
	   printf("Error: Cannot remove from empty queue!\n");
	   //exit(1);
   } else {
		node *newFront;
		newFront = q->front;
		int hold = q->front->data;
		printf("Value deQueued: %d.\n", hold);  //element at front of Queue
		q->front = q->front->next;
	   	q->count--;						//update size of queue
		free(newFront);					//delete front node
	}
}
