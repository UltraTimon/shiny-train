#ifndef __TIMESTWO
#define __TIMESTWO

typedef struct Node Node;

struct Node {
	int value;
	struct Node * next;
};

typedef struct List List;

struct LinkedList {
	Node * first;
	Node * last;
};

void add(int i);
void addFirst(int i);
void addLast(int i);

int get(int index);
int getFirst();
int getLast();

int remove(int index);
int removeFirst();
int removeLast();

#endif
