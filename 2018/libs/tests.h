#include <stdbool.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define RUN_TESTS(func) printf("Test: " #func "\n"); \
  func();

#define DESCRIBE(val) printf(" Case: %s\n", val);

void assert_true(bool actual, char *msg)
{
    if (actual == true) {
        printf("  -> OK: %s\n", msg);
    } else {
        printf("  -> FAIL: %s\n", msg);
    }
}

void assert_false(bool actual, char *msg)
{
    assert_true(actual ? false : true, msg);
}

template<typename T>
void assert_equals(T expected, T actual, string msg)
{
    if (expected != actual) {
        cout << "  -> FAIL: " << msg << endl
             << "      Expected '" << expected << "', but was '" << actual << "'." << endl;
    } else {
        cout << "  -> OK: " << msg << endl;
    }
}
