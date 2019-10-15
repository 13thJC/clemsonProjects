/* -------------------- */
/* queuetest.c             */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
	queue *newQ = initialize();		//create queue
	printf("Value of 'isempty': %d\n", isempty(newQ));
	dequeue(newQ);					// make sure deQ works when empty
	enqueue(newQ,1);
	enqueue(newQ, 50);
	printf("First in line: %d.\n", front(newQ));
	printf("Value of 'isempty': %d\n", isempty(newQ));
	dequeue(newQ);
	enqueue(newQ, 10);
	printf("Value of 'isempty': %d\n", isempty(newQ));
	printf("First in line: %d.\n", front(newQ));
	dequeue(newQ);
	printf("Value of 'isempty': %d\n", isempty(newQ));
	dequeue(newQ);
	dequeue(newQ);
	return(0);
}
