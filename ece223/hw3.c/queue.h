/* -------------------- */
/* queue.h             */
#ifndef Q_H
#define Q_H

/** list data pointer. not to be dereferenced or freed by the list. */
typedef int qdata;
/* pointer to opaque queue type*/
//typedef struct queue queue;
typedef void *q; 	//queue pointer

/*function declarations*/
void initialize(*q);
/*
void front();
void isempty();
void isfull();
void enqueue(q, qdata data);
qdata dequeue(q);
void destroy(*q);
*/
#endif Q_H
