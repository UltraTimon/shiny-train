#include <stdio.h>
#include "linkedlist.h"
#include <string.h>

typedef struct Node Node;

struct Node {
	int value;
	Node * next;
};

Node * newNode(int value) {
	Node * newNode = malloc(sizeof(int) + sizeof(Node *));
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void add(int i)
{
	
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

int getFirst()
{

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

