/* 
 * File:   bsearch_run.c
 * Author: prakbans
 * Created on September 21, 2014, 2:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "bsearch.h"

void integerSortAndSearch();
void stringSortAndSearch();

struct mi {
    int nr;
    char *name;
} months[] = {
    { 1, "jan"},
    { 2, "feb"},
    { 3, "mar"},
    { 4, "apr"},
    { 5, "may"},
    { 6, "jun"},
    { 7, "jul"},
    { 8, "aug"},
    { 9, "sep"},
    {10, "oct"},
    {11, "nov"},
    {12, "dec"}
};
#define nr_of_months (sizeof(months)/sizeof(months[0]))

static int
compmi(const void *m1, const void *m2) {
    struct mi *mi1 = (struct mi *) m1;
    struct mi *mi2 = (struct mi *) m2;
    return strcmp(mi1->name, mi2->name);
}

int nums[] = {12, 15, 17, 19, 22, 67};
#define nr_of_ints (sizeof(nums)/sizeof(nums[0]))

static int
compmi_int(const void *m1, const void *m2) {
    int *mi1 = (int *) m1;
    int *mi2 = (int *) m2;
    if (*mi1 < *mi2) return -1;
    else if (*mi1 > *mi2) return 1;
    else return 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    integerSortAndSearch();

    return (EXIT_SUCCESS);
}

void integerSortAndSearch() {
    int key = 120;
    int64_t *k = binarySearch(&key, nums, nr_of_ints,
            sizeof (int), compmi_int);

    int* res = (int*) k;


    if (res == NULL)
        printf("aq%saq: unknown month\n", "FAILURE HAHA");
    else
        printf("integer #%d\n", *res);
}

void stringSortAndSearch() {
    int i;
    qsort(months, nr_of_months, sizeof (struct mi), compmi);
    for (i = 1; i < 2; i++) {
        struct mi key;
        key.name = "jan";

        int64_t *k = binarySearch(&key, months, nr_of_months,
                sizeof (struct mi), compmi);

        printf("The value of k is %lx", k);
        struct mi* res = (struct mi*) k;

        if (res == NULL)
            printf("aq%saq: unknown month\n", "FAILURE HAHA");
        else
            printf("%s: month #%d\n", res->name, res->nr);
    }
}

