/**
 * Created By: 
 * Gurpreet Dhillon PID: A14220554
 *
 */

#include <stdio.h>
#include <stdlib.h> /* malloc */

#include "arraysort.h"

/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to the
 * list.
 */
list *createlist(int maxElements)
{
    list *newList = NULL;

    newList = (list *)malloc(sizeof(list));

    if (newList == NULL)
    {
        printf("Dynamic allocation of new list failure.");
        return NULL;
    }

    // initialize new list in heap.
    // Provide the max # of elements specified.
    newList->sortedList = (int *)calloc(maxElements, sizeof(int));
    //printf("%p", newList->sortedList);
    newList->size = 0;
    newList->maxSize = maxElements;

    return newList;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the list
 * to double its previous size and then insert the element. If the result of the
 * insert was not successful it should return -1. Note that the resulting list
 * should be sorted and there should be no information loss. The function should
 * return -1 if no valid list was passed to it.
 */
int insert(list *ls, int val)
{
    int i = 0, j;
    int *tmp;

    //Return -1 for invalid list
    if (ls == NULL)
    {
        return -1;
    }

    //If list is full, double maxSize first.
    if (ls->size == ls->maxSize)
    {
        // Increase size of sortedList in the heap.
        tmp = (int *)realloc(ls->sortedList, (ls->size * 2) * sizeof(int));
        if (tmp == NULL)
        {
            return -1;
        }

        ls->maxSize = ls->size * 2;
    }

    //find index where insert is required for val.
    //"i" will contain required index.
    for (i = 0; i < ls->size; ++i)
    {
        if (val < ls->sortedList[i])
        {
            break;
        }
    }

    /* Make space for val in correct index by shifting all values greater
	 * than val to the right by 1 index. This accounts for zero length
	 * "sorted" arrays as well.
	 */
    for (j = ls->size; j > i; --j)
    {
        ls->sortedList[j] = ls->sortedList[j - 1];
    }

    //Insert element into list
    ls->size++;
    ls->sortedList[i] = val;

    return i;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
int remove_val(list *ls, int val)
{
    int numDeleted = 0, i, j;

    //Guard against invalid list.
    if (ls == NULL)
    {
        return -1;
    }

    //find index where deletion is required for val.
    //"i" will contain required index.
    for (i = 0; i < ls->size; ++i)
    {
        if (val == ls->sortedList[i])
        {

            // Reduce size by 1
            (ls->size)--;

            //Shift all elements down 1 index for removal.
            for (j = i; j < ls->size; ++j)
            {
                ls->sortedList[j] = ls->sortedList[j + 1];
            }

            numDeleted++;
            --i; //Decrement i for any potential duplicates to be retested
        }
    }

    return numDeleted;
}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls)
{
    //Guard against invalid list.
    if (ls == NULL)
    {
        return -1;
    }

    if (ls->size != 0)
    {
        return ls->sortedList[(ls->size) - 1]; // array is 0 indexed.
    }
    else
    {
        return -1;
    }
}

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
int get_min_value(list *ls)
{
    //Guard against invalid list.
    if (ls == NULL)
    {
        return -1;
    }

    if (ls->size != 0)
    {
        return ls->sortedList[0]; // array is 0 indexed.
    }
    else
    {
        return -1;
    }
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val)
{
    int i;

    //Guard against invalid list.
    if (ls == NULL)
    {
        return -1;
    }

    for (i = 0; i < ls->size; ++i)
    {
        if (val == ls->sortedList[i])
        {
            return i;
        }
    }

    return -1;
}

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
int pop_min(list *ls)
{

    int minVal, i;

    //Guard against invalid list.
    if (ls == NULL)
    {
        return -1;
    }

    if (ls->size != 0)
    {
        (ls->size)--;
        minVal = ls->sortedList[0];

        //shift all elements towards the beginning of the list.
        for (i = 0; i < ls->size; ++i)
        {
            ls->sortedList[i] = ls->sortedList[i + 1];
        }

        return minVal;
    }

    return -1;
}

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
void print(list *ls)
{
    int j;

    for (j = 0; j < ls->size; ++j)
    {
        printf("%d ", ls->sortedList[j]);
    }
    printf("\n");
}

/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
int get_max_ARM(list *ls);
