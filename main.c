#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "arraysort.h"

int
main()
{
    test_insert();
    test_remove_val();
    test_get_max_value();
    test_get_min_value();
    test_search();
    test_pop_min();

    return 0;
}
