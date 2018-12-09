#include "tests.h"
#include "list.h"


void test_basic_list()
{
    auto my_list = new List<int>();

    assert_true(0 == my_list->count(), "List should have 0 items.");

    my_list->add(100);
    my_list->add(200);

    assert_true(2 == my_list->count(), "List should have 2 items.");
}

int main()
{
    RUN_TESTS(test_basic_list)
}
