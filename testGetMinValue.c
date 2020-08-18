/**
 * Filename: testGetMinValue.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the function get_min_value.
 * Date: 7/19/2017
 */

#include "arraysort.h" /* For get_min_value() function prototype */
#include "test.h"      /* For TEST() macro and stdio.h */

/**
 * int get_min_value(list *ls)
 *
 * Return minimum value in list
 * Returns -1 if empty list was passed.
 *
 * Precondition: list must contain sorted list.
 *               val must be int type.
 */

void testGetMinValue()
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
