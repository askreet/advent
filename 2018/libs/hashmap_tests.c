#include <string.h>
#include "hashmap.h"
#include "tests.h"

void test_basic_behavior() {
    struct HashMap *map = new_hashmap();

    assert_false(hashmap_has(map, 100), "A new HashMap should not contain 100.");
    hashmap_put(map, 100, (void *) 12345678);
    assert_true(12345678 == (int) hashmap_get(map, 100), "The value of key 100 should be 12345678.");
}

void test_negative_key() {
    struct HashMap *map = new_hashmap();

    assert_false(hashmap_has(map, -123), "A new HashMap should not contain -123.");
    hashmap_put(map, -1928321, (void *) 424242);
    assert_true(424242 == (int) hashmap_get(map, -1928321), "The value of should be 424242.");
}

void test_heavy_load() {
    struct HashMap *map = new_hashmap();

    for (int i = 0; i < 500000; i++) {
        hashmap_put(map, i * 1234, (void *) i);
        int get_value = (int) hashmap_get(map, i * 1234);
    }

    assert_true(true, "Nothing bad happened with many values.");
}

void test_iterator() {
    struct HashMap *map = new_hashmap();

    hashmap_put(map, 200, 4);
    hashmap_put(map, 300, 12);
    hashmap_put(map, 400, 100);

    for (HashMapIter* i = hashmap_iter(); !hashmap_done(i); hashmap_next(i)) {

    }
}

int main(int argc, char *argv[]) {
    RUN_TESTS(test_basic_behavior);
    RUN_TESTS(test_negative_key);
    RUN_TESTS(test_heavy_load);
}
