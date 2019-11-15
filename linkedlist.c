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
	if(list == NULL)
		return;

	Node * newNode = getNewNode(i);
	if(list->first == NULL) {
		list->first = newNode;
		list->last = newNode;
	} else if (list->first == list->last) {
		list->first->next = newNode;
		list->last = newNode;
	} else {
		list->last->next = newNode;
		list->last = newNode;
	}
}

void addFirst(int i, LinkedList * list)
{
	if(list == NULL)
		return;
		
	Node * newNode = getNewNode(i);
	newNode->next = list->first;
	list->first = newNode;
	if(list->last == NULL) 
		list->last = newNode;
}

void addLast(int i, LinkedList * list)
{
	if(list == NULL)
		return;
		
	Node * newNode = getNewNode(i);
	if(list->first == NULL) {
		list->first = newNode;
		list->last = newNode;
	} else {
		list->last->next = newNode;
		list->last = newNode;
	}
}

// 0-indexed
int get(int index, LinkedList * list)
{
	if(list == NULL)
		return -1;

	int count = 0;
	Node * current = list->first;
	if(current == NULL)
		return -1;
	
	while(count != index) {
		if(current->next == NULL) 
			return -1;
		current = current->next;
		count++;
	}

	return current->value;
}

int getFirst(LinkedList * list) 
{
	if(list == NULL)
		return -1;

	if(list->first == NULL)
		return -1;
	else
		return list->first->value;
}

int getLast(LinkedList * list)
{
	if(list == NULL)
		return -1;

	Node * node = list->last;
	if(node == NULL)
		return -1;
	else 
		return node->value;
}

int size(LinkedList * list) {
	
	if(list == NULL || list->first == NULL)
		return 0;

	int count = 1;
	Node * current = list->first;

	while(current->next != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

int removeNode(int index, LinkedList * list)
{
	if(list == NULL || list->first == NULL)
		return 0;

	return index;	
}

int removeFirst(LinkedList * list) {
	return removeNode(0, list);
}

int removeLast(LinkedList * list) {
	return removeNode(size(list) - 1, list);
}
