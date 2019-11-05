#ifndef __TIMESTWO
#define __TIMESTWO

typedef struct Node Node;

struct Node {
	int value;
	struct Node * next;
};

typedef struct LinkedList LinkedList;

struct LinkedList {
	Node * first;
	Node * last;
};

LinkedList * getNewLinkedList();

void add(int i, LinkedList * list);
void addFirst(int i);
void addLast(int i);

int get(int index, LinkedList * list);
int getFirst(LinkedList * list);
int getLast();

int removeNode(int index);
int removeFirst();
int removeLast();

#endif
