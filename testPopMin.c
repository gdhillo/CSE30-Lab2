/**
 * Filename: testPopMin.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the function pop_min.
 * Date: 7/19/2017
 */

#include "arraysort.h" /* For pop_min() function prototype */
#include "test.h"      /* For TEST() macro and stdio.h */

/**
 * int pop_min(list *ls)
 *
 * Return minimum value in list
 * Returns -1 if empty list was passed.
 *
 * Precondition: list must be sorted.
 *
 */

void testPopMin()
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
    print(testList);

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
