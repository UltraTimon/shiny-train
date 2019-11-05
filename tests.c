#include <stdio.h>
#include "minunit.h"
#include "linkedlist.h"
#include <string.h>

int tests_run = 0;

// --------------------------------------------------------------------------------

static char * positive_number_test() {
    mu_assert("number should be multiplied by two", timesTwo(4) == 8);
    return 0;
}

static char * negative_number_test() {
    mu_assert("negative number should yield negative double", timesTwo(-4) == -8);
    return 0;
}

static char * zero_test() {
    mu_assert("zero times two should yield zero", timesTwo(0) == 0);
    return 0;
}

static char * simple_name_test() {
	char result[20];
	greetMe(result);

    mu_assert("name should be greeted", strcmp("Hi, there!", greetMe(result)) == 0);

    return 0;
}



// ------------------------------------------------------------------------------------

static char * all_tests() {
    mu_run_test(positive_number_test);
    mu_run_test(negative_number_test);
    mu_run_test(zero_test);
    mu_run_test(simple_name_test);
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

    return result != 0;
}
