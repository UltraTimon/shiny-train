#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int use_case() {

    printf("Example use case: Fill the list with 1-5, then remove the first and third entry.\n");

    LinkedList * list = getNewLinkedList();
    for(int i = 1; i < 6; i++) {
        add(i, list);
    }

    printf("first round: \n");
    for(int index = 0; index < size(list); index++) {
        printf("%d\n", get(index, list));
    }

    removeFirst(list);
    removeNode(2, list);

    printf("second round: \n");
    for(int index = 0; index < size(list); index++) {
        printf("%d\n", get(index, list));
    }
     
    destroyList(list);
    printf("the end! %d\n", size(list));
    return 0;
}