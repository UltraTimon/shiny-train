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

// ------------------------------------------------------------------------------------

static char * all_tests() {
    mu_run_test(one_element_test);
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
