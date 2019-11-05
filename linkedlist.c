#include <stdio.h>
#include "linkedlist.h"
#include <string.h>

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

LinkedList * getNewLinkedList() {
	LinkedList * newList = malloc(sizeof(Node *));
	newList->first = NULL;
	newList->last = NULL;

	return newList;
}

Node * getNewNode(int value) {
	Node * newNode = malloc(sizeof(int) + sizeof(Node *));
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void add(int i, LinkedList * list)
{
	Node * newNode = getNewNode(i);
	if(list->first == NULL) {
		list->first = newNode;
		list->last = newNode;
		return;
	} else {
		list->last->next = newNode;
	}
}

void addFirst(int i)
{

}

void addLast(int i)
{

}

int get(int index)
{
	
}

int getFirst(LinkedList * list) 
{
	if(list->first == NULL)
		return -1;
	else
		return list->first->value;
}

int getLast()
{

}

int remove(int index)
{

}

int removeFirst()
{

}

int removeLast()
{

}

