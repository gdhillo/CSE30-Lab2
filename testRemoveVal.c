/*
 * Filename: testRemoveVal.c
 * Gurpreet Dhillon PID: A14220554
 * Description: Unit test program to test the function remove_val.
 * Date: 7/19/2017
 */

#include "arraysort.h" /* For remove_val() function prototype */
#include "test.h"      /* For TEST() macro and stdio.h */

/*
 * int remove_val(list *ls, int val)
 *
 * Return the number of deleted elements.
 * Returns -1 if no valid list was passed to it.
 *
 * Precondition: val is integer type.
 *               Otherwise, data will be implicitly cast.
 */

void testRemoveVal()
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
