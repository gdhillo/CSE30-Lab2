/**
 * Filename: test_arraysort.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the file arraysort.c
 * Date: 7/19/2017
 */

#include "arraysort.h"
#include <limits.h> /* For LONG_MIN & LONG_MAX */
#include "test.h"   /* For TEST() macro and stdio.h */

/**
 * int insert(list *ls, int val);
 *
 * Return the index where the element was inserted.
 * Returns -1 if no valid list was passed to it.
 *
 * Precondition: val is integer type.
 *               Otherwise, data will be implicitly cast.
 */

void test_insert()
{
    printf("\nTesting insert()\n");

    /* Create empty list of size 5 for testing */
    list *testList = createlist(5);
    list *invalidList = NULL;

    /* Initial list size: [ ] */
    TEST(testList->size == 0);

    /* Testing successful insert. Index of insert should be returned. */
    TEST(insert(testList, 3) == 0);
    TEST(insert(testList, 1) == 0);
    TEST(insert(testList, 4) == 2);
    TEST(insert(testList, -1) == 0);
    TEST(insert(testList, 5) == 4);
    TEST(insert(testList, 0) == 1);
    TEST(insert(testList, 2) == 3);
    TEST(insert(testList, 7) == 7);
    TEST(insert(testList, 2) == 4);
    TEST(insert(testList, -1) == 1);

    /* List after insert: [ -1 -1, 0, 1, 2, 2, 3, 4, 5, 7 ] size = 10 */
    TEST(testList->maxSize == 10);

    /* Testing insert after increasing max size */
    TEST(insert(testList, 3) == 7); /* [-1-1,0,1,2,2,3,3,4,5,7] size = 11*/

    /* Testing max size successfully doubled */
    TEST(testList->maxSize == 20);

    /* Testing invalid list */
    TEST(insert(invalidList, -4) == -1);

    /* Testing insert with int range. */
    TEST(insert(testList, LONG_MIN) == 0);
    TEST(insert(testList, LONG_MAX) == 12);
    /* List after insert: [ LONG_MIN,-1-1,0,1,2,2,3,3,4,5,7,LONG_MAX ] */

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on insert()\n");
}

/**
 * int remove_val(list *ls, int val)
 *
 * Return the number of deleted elements.
 * Returns -1 if no valid list was passed to it.
 *
 * Precondition: val is integer type.
 *               Otherwise, data will be implicitly cast.
 */

void test_remove_val()
{
    printf("\nTesting remove_val()\n");

    /* Create empty list of size 5 for testing */
    list *testList = createlist(5);
    list *invalidList = NULL;

    /* Initial list size: [ ] */
    TEST(testList->size == 0);

    // populate list
    insert(testList, 3);
    insert(testList, 1);
    insert(testList, 4);
    insert(testList, -1);
    insert(testList, 5);
    insert(testList, 0);
    insert(testList, 2);
    insert(testList, 7);
    insert(testList, 2);
    insert(testList, -1);

    /* List after insert: [ -1 -1, 0, 1, 2, 2, 3, 4, 5, 7 ] size = 10 */

    /* Testing maxSize is correct BEFORE removing elements */
    TEST(testList->maxSize == 10);

    /* Testing successful removes. Index of insert should be returned. */
    TEST(remove_val(testList, 1) == 1);  /*[-1,-1,0,2,2,3,4,5,7] size = 9 */
    TEST(remove_val(testList, 2) == 2);  /*[-1,-1,0,3,4,5,7] size = 7 */
    TEST(remove_val(testList, 7) == 1);  /*[-1,-1,0,3,4,5] size = 6 */
    TEST(remove_val(testList, -1) == 2); /*[0,3,4,5] size = 4 */

    /* Testing size of list after multiple removes */
    TEST(testList->size == 4);

    TEST(remove_val(testList, 5) == 1); /*[0,3,4] size = 3 */
    TEST(remove_val(testList, 4) == 1); /*[0,3] size = 2 */
    TEST(remove_val(testList, 0) == 1); /*[3] size = 1 */
    TEST(remove_val(testList, 3) == 1); /*[] size = 0 */

    /* Testing size of empty list */
    TEST(testList->size == 0);

    /* Testing that maxSize did not change AFTER removing elements*/
    TEST(testList->maxSize == 10);

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on remove_val()\n");
}

/**
 * int get_max_value(list *ls)
 *
 * Return maximum value in list
 * Returns -1 if empty list was passed.
 *
 * Precondition: list must contain sorted list.
 *               val must be int type.
 */

void test_get_max_value()
{
    printf("\nTesting get_max_value()\n");

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

    /* Testing maxSize is correct BEFORE removing elements */
    TEST(testList->maxSize == 10);

    /* Testing successful insert. Index of insert should be returned. */
    TEST(get_max_value(testList) == 7);

    TEST(remove_val(testList, 7) == 1); /*[-2,-2,0,1,2,2,3,4,5] max = 5*/
    TEST(get_max_value(testList) == 5);

    TEST(remove_val(testList, 5) == 1); /*[-2,-2,0,1,2,2,3,4] max = 4 */
    TEST(get_max_value(testList) == 4);

    TEST(remove_val(testList, 4) == 1); /*[-2,-2,0,1,2,2,3] max = 3 */
    TEST(get_max_value(testList) == 3);

    TEST(remove_val(testList, 3) == 1); /*[-2,-2,0,1,2,2] max = 2 */
    TEST(get_max_value(testList) == 2);

    TEST(remove_val(testList, 2) == 2); /*[-2,-2,0,1] max = 1 */
    TEST(get_max_value(testList) == 1);

    TEST(remove_val(testList, 1) == 1); /*[-2,-2,0] max = -2 */
    TEST(get_max_value(testList) == 0);

    TEST(remove_val(testList, 0) == 1); /*[-2,-2] max = -2 */
    TEST(get_max_value(testList) == -2);

    TEST(remove_val(testList, -2) == 2); /*[] max = -1 */
    TEST(get_max_value(testList) == -1); /* <-- empty list should return -1 */

    /* Testing size of list after multiple removes */
    TEST(testList->size == 0);

    /* Testing that maxSize did not change AFTER removing elements*/
    TEST(testList->maxSize == 10);

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on get_max_value()\n");
}

/**
 * int get_min_value(list *ls)
 *
 * Return minimum value in list
 * Returns -1 if empty list was passed.
 *
 * Precondition: list must contain sorted list.
 *               val must be int type.
 */

void test_get_min_value()
{
    printf("\nTesting get_min_value()\n");

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

    /* Testing minSize is correct BEFORE removing elements */
    TEST(testList->maxSize == 10);

    /* Testing successful insert. Index of insert should be returned. */
    TEST(get_min_value(testList) == -2);

    TEST(remove_val(testList, -2) == 2); /*[0,1,2,2,3,4,5,7] min - 0*/
    TEST(get_min_value(testList) == 0);

    TEST(remove_val(testList, 0) == 1); /*[1,2,2,3,4,5,7] min = 1 */
    TEST(get_min_value(testList) == 1);

    TEST(remove_val(testList, 1) == 1); /*[2,2,3,4,5,7] min = 2 */
    TEST(get_min_value(testList) == 2);

    TEST(remove_val(testList, 2) == 2); /*[3,4,5,7] min = 3 */
    TEST(get_min_value(testList) == 3);

    TEST(remove_val(testList, 3) == 1); /*[4,5,7] min = 4 */
    TEST(get_min_value(testList) == 4);

    TEST(remove_val(testList, 4) == 1); /*[5,7] min = 5 */
    TEST(get_min_value(testList) == 5);

    TEST(remove_val(testList, 5) == 1); /*[7] min = 7 */
    TEST(get_min_value(testList) == 7);

    TEST(remove_val(testList, 7) == 1);  /*[] min = -1 */
    TEST(get_min_value(testList) == -1); /* <-- empty list should return -1 */

    /* Testing size of list after multiple removes */
    TEST(testList->size == 0);

    /* Testing that minSize did not change AFTER removing elements*/
    TEST(testList->maxSize == 10);

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on get_min_value()\n");
}

/**
 * int search(list *ls, int val);
 *
 * Return the index of the first occurrence of 'val' in the list.
 * Returns -1 if value 'val' is not in the provided list.
 *
 * Precondition: Valid list has been created.
 *
 */

void test_search()
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

/**
 * int pop_min(list *ls)
 *
 * Return minimum value in list
 * Returns -1 if empty list was passed.
 *
 * Precondition: list must be sorted.
 *
 */

void test_pop_min()
{
    printf("\nTesting pop_min()\n");

    /* Create empty list of size 5 for testing */
    list *testList = createlist(5);

    /* Initial list size: [ ] */
    TEST(testList->size == 0);

    /* Populate list */
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

    /* Testing minSize is correct BEFORE popping elements */
    TEST(testList->maxSize == 10);

    /* Testing successful pop. Min val should be returned. */
    TEST(pop_min(testList) == -2); /*[-2,0,1,2,2,3,4,5,7] min = 0*/
    TEST(pop_min(testList) == -2); /*[0,1,2,2,3,4,5,7] min = 0*/
    TEST(pop_min(testList) == 0);  /*[1,2,2,3,4,5,7] min = 1 */
    TEST(pop_min(testList) == 1);  /*[2,2,3,4,5,7] min = 2 */
    TEST(pop_min(testList) == 2);  /*[2,3,4,5,7] min = 2 */
    TEST(pop_min(testList) == 2);  /*[3,4,5,7] min = 3 */
    TEST(pop_min(testList) == 3);  /*[4,5,7] min = 4 */
    TEST(pop_min(testList) == 4);  /*[5,7] min = 5 */
    TEST(pop_min(testList) == 5);  /*[7] min = 7 */
    TEST(pop_min(testList) == 7);  /*[] min = -1 */
    TEST(pop_min(testList) == -1); /* <-- empty list should return -1 */

    /* Testing size of list after all elements have been popped */
    TEST(testList->size == 0);

    /* Testing that minSize did not change AFTER popping elements*/
    TEST(testList->maxSize == 10);

    free(testList->sortedList);
    free(testList);

    printf("Finished running tests on pop_min()\n");
}
