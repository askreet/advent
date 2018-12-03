#include <stdio.h>
#include <stdbool.h>
#include "int_set.h"
#include "tests.h"

void test_basic_behavior()
{
  struct IntSet set = new_int_set();

  assert_false(int_set_includes(&set, 0), "A new set should not include 0.");
  int_set_add(&set, 0);
  assert_true(int_set_includes(&set, 0), "A set with 0 added should include 0.");
}

void test_prepending_values()
{
  struct IntSet new_set = new_int_set();

  int_set_add(&new_set, 100);
  int_set_add(&new_set, 10);
  int_set_add(&new_set, 4);
  assert_true(int_set_includes(&new_set, 4), "Set should include 4.");
  assert_true(int_set_includes(&new_set, 10), "Set should include 10.");
  assert_true(int_set_includes(&new_set, 100), "Set should include 100.");
  assert_false(int_set_includes(&new_set, 1), "Set should not include 1.");
}

void test_even_odd_values()
{
  struct IntSet set = new_int_set();

  int_set_add(&set, 1);
  int_set_add(&set, 2);
  int_set_add(&set, 3);
  int_set_add(&set, 4);

  assert_true(int_set_includes(&set, 1), "Set should include 1.");
  assert_true(int_set_includes(&set, 2), "Set should include 2.");
  assert_true(int_set_includes(&set, 3), "Set should include 3.");
  assert_true(int_set_includes(&set, 4), "Set should include 4.");
}

void test_large_set()
{
  struct IntSet set = new_int_set();

  for (int i = 0; i <= 4096; i++) {
    int_set_add(&set, i);
  }

  assert_true(int_set_includes(&set, 100), "A set with 4,096 numbers should include 100.");
  assert_true(int_set_includes(&set, 513), "A set with 4,096 numbers should include 513.");
  assert_true(int_set_includes(&set, 4095), "A set with 4,096 numbers should include 4095.");
  assert_false(int_set_includes(&set, 4097), "A set with 4,096 numbers should not include 4097.");
}

int main(int argc, char* argv[])
{
  RUN_TESTS(test_basic_behavior);
  RUN_TESTS(test_prepending_values);
  RUN_TESTS(test_even_odd_values);
  RUN_TESTS(test_large_set);
  
  return 0;
}

