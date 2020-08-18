/**
 * Filename: testSearch.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the function search.
 * Date: 7/19/2017
 */

#include "arraysort.h" /* For search() function prototype */
#include <limits.h>    /* For LONG_MIN & LONG_MAX */
#include "test.h"      /* For TEST() macro and stdio.h */

/**
 * int search(list *ls, int val);
 *
 * Return the index of the first occurrence of 'val' in the list.
 * Returns -1 if value 'val' is not in the provided list.
 *
 * Precondition: Valid list has been created.
 *
 */

void testSearch()
{
    printf("\nTesting search()\n");

    /* Create empty list of size 5 for testing */
    list *testList = createlist(5);
    list *invalidList = NULL;

    /* Initial list size: [ ] */
    TEST(testList->size == 0);

    // populate list
    insert(testList, 3);
    insert(testList, 1);
    insert(testList, 4);
    insert(testList, -2);
    insert(testList, 5);
    insert(testList, 0);
    insert(testList, 2);
    insert(testList, 7);
    insert(testList, 2);
    insert(testList, -2);

    /* List after insert: [ -2 -2, 0, 1, 2, 2, 3, 4, 5, 7 ] size = 10 */

    /* Testing successful search. Index of search should be returned. */
    TEST(search(testList, 0) == 2);
    TEST(search(testList, 2) == 4);
    TEST(search(testList, 7) == 9);
    TEST(search(testList, -2) == 0);

    /* Testing invalid val */
    TEST(search(testList, -4) == -1);

    /* Testing search with int range. */
    insert(testList, LONG_MIN);
    insert(testList, LONG_MAX);

    TEST(search(testList, LONG_MIN) == 0);
    TEST(search(testList, LONG_MAX) == 11);
    /* List after search: [ LONG_MIN, -2 -2, 0, 1, 2, 2, 3, 4, 5, 7, LONG_MAX] */

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on search()\n");
}
