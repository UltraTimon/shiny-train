#include <stdio.h>
#include "minunit.h"
#include "linkedlist.h"
#include <string.h>
#include "example_use.h"

int tests_run = 0;

// Setup

LinkedList * myList;

// --------------------------------------------------------------------------------

static char * getFirst_test() {
    myList = getNewLinkedList();

    add(5, myList);
    mu_assert("first element should be 5", getFirst(myList) == 5);
    return 0;
}

static char * getLast_test() {
    myList = getNewLinkedList();

    add(7, myList);
    add(5, myList);
    mu_assert("last element should be 5", getLast(myList) == 5);

    LinkedList * newList = getNewLinkedList();
    mu_assert("getlast should return NULL on empty list", getLast(newList) == -1);
    return 0;
}

static char * get_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    mu_assert("second element should be 7", get(1, myList) == 7);
    return 0;
}

static char * addFirst_test() {
    myList = getNewLinkedList();

    mu_assert("size should be 0", size(myList) == 0);
    add(5, myList);
    mu_assert("size should be 1", size(myList) == 1);
    add(7, myList);
    mu_assert("size should be 2", size(myList) == 2);
    addFirst(3, myList);
    mu_assert("size should be 3", size(myList) == 3);
    mu_assert("first element should be 3", get(0, myList) == 3);
    mu_assert("second element should be 3", get(1, myList) == 5);

    LinkedList * newList = getNewLinkedList();
    addFirst(3, newList);
    mu_assert("first element should be 3, even with a new list", get(0, newList) == 3);
    return 0;
}

static char * addLast_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    addLast(3, myList);
    mu_assert("last element should be 3", get(2, myList) == 3);

    LinkedList * newList = getNewLinkedList();
    addLast(3, newList);
    mu_assert("last element should be 3, even with a new list", get(0, newList) == 3);
    return 0;
}

static char * removeNode_and_size_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    add(3, myList);
    mu_assert("size should be 3", size(myList) == 3);
    mu_assert("last element is 3, should be returned by remove", removeNode(2, myList) == 3);
    mu_assert("size should be 2", size(myList) == 2);
    mu_assert("first element is 5, should be returned by remove", removeNode(0, myList) == 5);
    mu_assert("size should be 1", size(myList) == 1);
    mu_assert("only element is 7, should be returned by remove", removeNode(0, myList) == 7);
    mu_assert("size should be 0", size(myList) == 0);

    mu_assert("removeNode on empty list should return -1 regardless of index", removeNode(1253, myList) == -1);
    return 0;
}

static char * bad_flow_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    addLast(3, myList);
    mu_assert("get: negative index should return -1", get(-1, myList) == -1);
    mu_assert("get: positive out of range index should return -1", get(3, myList) == -1);

    mu_assert("removeNode: negative index should return -1", removeNode(-1, myList) == -1);
    mu_assert("removeNode: positive out of range index should return -1", removeNode(3, myList) == -1);

    return 0;
}

static char * remove_first_and_last_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    add(3, myList);
    mu_assert("last element is 3, should be returned by removeLast", removeLast(myList) == 3);
    mu_assert("first element is 5, should be returned by removeFirst", removeFirst(myList) == 5);
    mu_assert("only element is 7, should be returned by removeLast", removeLast(myList) == 7);

    add(1, myList);
    mu_assert("only element is 1, should be returned by removeFirst", removeFirst(myList) == 1);

    mu_assert("removeLast on empty list should return -1", removeLast(myList) == -1);
    mu_assert("removeFirst on empty list should return -1", removeFirst(myList) == -1);
    return 0;
}

static char * remove_list_test() {
    myList = getNewLinkedList();

    add(5, myList);
    add(7, myList);
    add(3, myList);
    mu_assert("size should be 3 after inserting", size(myList) == 3);
    removeList(myList);
    mu_assert("size should be 0 after removing all nodes", size(myList) == 0);
    mu_assert("pointer to list should be NULL", myList == NULL);
    return 0;
}

// ------------------------------------------------------------------------------------

static char * all_tests() {
    mu_run_test(getFirst_test);
    mu_run_test(getLast_test);
    mu_run_test(get_test);
    mu_run_test(addFirst_test);
    mu_run_test(addLast_test);
    mu_run_test(removeNode_and_size_test);
    mu_run_test(bad_flow_test);
    mu_run_test(remove_first_and_last_test);
    mu_run_test(remove_list_test);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    use_case();

    return result != 0;
}
