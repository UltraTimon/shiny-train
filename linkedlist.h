#ifndef __TIMESTWO
#define __TIMESTWO

typedef struct Node Node;

struct Node {
	int value;
	Node * next;
};

typedef struct LinkedList LinkedList;

struct LinkedList {
	Node * first;
	Node * last;
};

LinkedList * getNewLinkedList();

void add(int i, LinkedList * list);
void addFirst(int i, LinkedList * list);
void addLast(int i, LinkedList * list);

int get(int index, LinkedList * list);
int getFirst(LinkedList * list);
int getLast();

int removeNode(int index, LinkedList * list);
int removeFirst(LinkedList * list);
int removeLast(LinkedList * list);
void destroyList(LinkedList * list);

int size(LinkedList * list);
void printAllElements();


#endif
