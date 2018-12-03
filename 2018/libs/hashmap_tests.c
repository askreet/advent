#include "hashmap.h"
#include "tests.h"

void test_basic_behavior()
{
  struct HashMap* map = new_hashmap();

  assert_false(hashmap_has(map, 100), "A new HashMap should not contain 100.");
  hashmap_put(map, 100, (void*) 12345678);
  assert_true(12345678 == (int) hashmap_get(map, 100), "The value of key 100 should be 12345678.");
}

int main(int argc, char* argv[])
{
  RUN_TESTS(test_basic_behavior);
}
