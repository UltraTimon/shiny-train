#include <stdio.h>
#include "linkedlist.h"
#include <string.h>
#include <stdlib.h>

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

/** 0-indexed */
int get(int index, LinkedList * list)
{
	int count = 0;
	Node * current = getFirst(list);
	if(current = NULL)
		return NULL;
	
	while(count != index) {
		if(current->next == NULL) 
			return NULL;
		current = current->next;
		count++;
	}

	return current->value;
}

int getFirst(LinkedList * list) 
{
	if(list->first == NULL)
		return -1;
	else
		return list->first->value;
}

// int getLast()
// {

// }

// int removeNode(int index)
// {

// }

// int removeFirst()
// {

// }

// int removeLast()
// {

// }

