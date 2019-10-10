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
	if ((q->front == NULL) && (q->rear == NULL)) {
       printf("\nQueue is empty." );
	   return 1;
   } else {
	   printf("\nQueue is not empty." );
	   printf("\n");
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
	if (!isempty(q)) {
		q->rear->next = temp;
		q->rear = temp;
	// if empty, insert first node into queue
	} else {
		q->front = q->rear = temp;
	}
	q->count++;							// update size of queue
}

/* function to delete the front node and return its value
qdata dequeue(q) {
	qHeader *header = (qHeader *)malloc(sizeof(qHeader));
	q = header;

	node *temp; 			//create a new node to add to the queue
	temp = (node *)malloc(sizeof(node));
	temp = q->front; 		//point the temp node to the front of the queue
	int hold = temp->data;	//store the value of data into a temp variable
	q->front = q->front->next;	//make the next node in the queue front
	free(temp);					//delete the front node
	q->count--;					//decrement the amount of elements in queue
	return hold;				//return the value from the old front
} */
int main() {
	queue *newQueue = initialize();		//create queue
	isempty(newQueue);					//check to see if queue is empty
	enqueue(newQueue,1);
	isempty(newQueue);
	return(0);
}
