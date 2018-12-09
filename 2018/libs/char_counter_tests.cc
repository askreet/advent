#include <iostream>
#include "tests.h"
#include "char_counter.hh"

struct TestCase {
    const char* input;
    bool should_have_two;
    bool should_have_three;
};

void test_counting_chars()
{
    TestCase cases[] = {
            { "abcdef", false, false },
            { "bababc", true, true },
            { "abbcde", true, false },
            { "abcccd", false, true },
            { "aabcdd", true, false },
            { "abcdee", true, false },
            { "ababab", false, true },
    };

    for (auto test_case : cases) {
        CharCounter cc(test_case.input);

        CASE(test_case.input);

        if (test_case.should_have_two) {
            assert_true(cc.has_count_of(2), "Should have 2 characters.");
        } else {
            assert_false(cc.has_count_of(2), "Should not have 2 characters.");
        }

        if (test_case.should_have_three) {
            assert_true(cc.has_count_of(3), "Should have 3 characters.");
        } else {
            assert_false(cc.has_count_of(3), "Should not have 3 characters.");
        }
    }
}

int main()
{
    RUN_TESTS(test_counting_chars)
}
