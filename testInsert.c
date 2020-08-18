/*
 * Filename: testInsert.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the function insert.
 * Date: 7/19/2017
 */

#include "arraysort.h" /* For insert() function prototype */
#include <limits.h>    /* For LONG_MIN & LONG_MAX */
#include "test.h"      /* For TEST() macro and stdio.h */

/*	
 * int insert(list *ls, int val);
 *
 * Return the index where the element was inserted.
 * Returns -1 if no valid list was passed to it.
 *
 * Precondition: val is integer type. 
 *               Otherwise, data will be implicitly cast.
 */

void testInsert()
{
    printf("\nTesting insert()\n");

    /* Create empty list of size 5 for testing */
    list *testList = createlist(5);
    list *invalidList = NULL;

    /* Initial list size: [ ] */
    TEST(testList->size == 0);

    /* Testing successful insert. Index of insert should be returned. */
    TEST(insert(testList, 1) == 0);
    TEST(insert(testList, 4) == 1);
    TEST(insert(testList, 2) == 1);
    TEST(insert(testList, 5) == 3);
    TEST(insert(testList, -1) == 0);

    /* List after insert: [ -1, 1, 2, 4, 5 ] */
    TEST(testList->maxSize == 5);

    /* Testing insert after increasing max size */
    TEST(insert(testList, 3) == 3);

    /* Testing max size successfully doubled */
    TEST(testList->maxSize == 10);

    /* Testing successful insert. Index of insert should be returned. */
    TEST(insert(testList, 0) == 1);
    TEST(insert(testList, 2) == 3);
    TEST(insert(testList, 7) == 8);
    TEST(insert(testList, -1) == 0);

    /* List after insert: [ -1, 0, 1, 2, 2, 3, 4, 5, 7 ] */

    /* Testing invalid list */
    TEST(insert(invalidList, 4) == -1);

    /* Testing insert with int range. */
    TEST(insert(testList, LONG_MIN) == 0);
    TEST(insert(testList, LONG_MAX) == 11);
    /* List after insert: [ LONG_MIN, -1, 0, 1, 2, 2, 3, 4, 5, 7, LONG_MAX ] */

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on insert()\n");
}
