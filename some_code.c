#include <stdio.h>
#include "some_code.h"
#include <string.h>

int timesTwo(int n) {
    return 2 * n;
}

// writes a string to the given char pointer
// purpose of this method is to also create a unit test
// 		for comparing the result of a string
char * greetMe(char * target) {
	target = "Hi, there!";
	return target;
}
