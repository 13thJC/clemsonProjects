#define MAXCOUNT 10		/* Q's can hold at most MAXCOUNT items */

typedef int PQitem;   /* to start with, PQitems are just integers */

typedef struct PQNodeTag {
  	PQitem				NodeItem;
    struct PQNodeTag	*link;
} PQListNode;

typedef struct {
	int 		count;
	PQListNode	*itemList;
} priorityQueue;
