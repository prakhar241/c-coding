/*
 * File:   list_test.c
 * Author: prakbans
 *
 * Created on Sep 21, 2014, 12:14:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Simple C Test Suite
 */

void list_with_ints();

void testList_with_ints() {
    list_with_ints();
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testList_with_ints (list_test) message=error message sample\n");
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% list_test\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testList_with_ints (list_test)\n");
    testList_with_ints();
    printf("%%TEST_FINISHED%% time=0 testList_with_ints (list_test)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
