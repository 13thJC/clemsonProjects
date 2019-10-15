/* -------------------- */
/* queue.h             */
#ifndef Q_H
#define Q_H

/** list data pointer. not to be dereferenced or freed by the list. */
typedef int qdata;
/* pointer to opaque queue type*/
typedef	struct Queue queue;

/*function declarations*/
queue* initialize();
int isempty(queue *q);
void enqueue(queue *q, qdata data);
int front(queue *q);
void dequeue(queue *q);
#endif
