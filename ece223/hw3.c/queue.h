/* -------------------- */
/* queue.h             */
#ifndef Q_H
#define Q_H

/** list data pointer. not to be dereferenced or freed by the list. */
//typedef void *qdata;
typedef int qdata;
/* pointer to opaque queue type*/
typedef struct queue queue;
typedef queue *q; 	//queue pointer

/*function declarations*/
void initialize(*q);
front();
void isempty();
isfull();
void enqueue(q, qdata data);
qdata dequeue(q);
destroy(*q);

#endif Q_H
