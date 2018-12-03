#include <stdbool.h>
#include <stdio.h>

#define RUN_TESTS(func) printf("Test: " #func "\n"); \
  func();

void assert_true(bool actual, char* msg)
{
  if (actual == true) {
    printf("-> OK: %s\n", msg);
  } else {
    printf("-> FAIL: %s\n", msg);
  }
}

void assert_false(bool actual, char* msg)
{
  assert_true(actual ? false : true, msg);
}
