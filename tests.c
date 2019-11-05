#include <stdio.h>
#include "minunit.h"
#include "linkedlist.h"
#include <string.h>

int tests_run = 0;

// Setup

LinkedList * myList;

// --------------------------------------------------------------------------------

static char * one_element_test() {
    add(5, myList);
    mu_assert("first element should be 5", getFirst(myList) == 5);
    return 0;
}

static char * two_element_test() {
    add(5, myList);
    add(7, myList);
    // printf("res: %d\n",get(2, myList));
    mu_assert("second element should be 7", get(1, myList) == 7);
    return 0;
}

static char * addFirst_test() {
    add(5, myList);
    add(7, myList);
    addFirst(3, myList);
    // printf("res: %d\n",get(0, getNewLinkedList()));
    mu_assert("first element should be 3", get(0, myList) == 3);
    mu_assert("second element should be 3", get(1, myList) == 5);

    LinkedList * newList = getNewLinkedList();
    addFirst(3, newList);
    mu_assert("first element should be 3, even with a new list", get(0, newList) == 3);
    return 0;
}

static char * addLast_test() {
    add(5, myList);
    add(7, myList);
    addLast(3, myList);
    // printf("res: %d\n",get(0, getNewLinkedList()));
    mu_assert("last element should be 3", get(2, myList) == 3);

    LinkedList * newList = getNewLinkedList();
    addLast(3, newList);
    mu_assert("last element should be 3, even with a new list", get(0, newList) == 3);
    return 0;
}

// ------------------------------------------------------------------------------------

static char * all_tests() {
    mu_run_test(one_element_test);
    mu_run_test(two_element_test);
    mu_run_test(addFirst_test);
    mu_run_test(addLast_test);
    return 0;
}

int main(int argc, char **argv) {
    // setup
    myList = getNewLinkedList();

    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
