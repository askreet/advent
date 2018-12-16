#include "../libs/tests.h"
#include "fabric_claim.hh"

void test_basic()
{
    string line("#1 @ 1,3: 4x5\n");

    fabric_claim claim(line);

    DESCRIBE(line.c_str());
    assert_equals(1, claim.id, "Should have an ID of 1.");
    assert_equals(1, claim.x, "Should have an X value of 1.");
    assert_equals(3, claim.y, "Should have a Y value of 3.");
    assert_equals(4, claim.width, "Should have a width of 4.");
    assert_equals(5, claim.height, "Should have a height of 5.");
}

void test_overlaps_with()
{
    string input1("#1 @ 1,3: 4x4");
    fabric_claim claim1(input1);

    string input2("#2 @ 3,1: 4x4");
    fabric_claim claim2(input2);

    string input3("#3 @ 5,5: 2x2");
    fabric_claim claim3(input3);

    DESCRIBE("Claim 1");
    assert_true(claim1.overlaps_with(claim2), "Should overlap with Claim 2.");
    assert_false(claim1.overlaps_with(claim3), "Should not overlap with Claim 3.");

    DESCRIBE("Claim 2");
    assert_true(claim2.overlaps_with(claim1), "Should overlap with Claim 1.");
    assert_false(claim2.overlaps_with(claim3), "Should not overlap with Claim 3.");

    DESCRIBE("Claim 3");
    assert_false(claim3.overlaps_with(claim1), "Should not overlap with Claim 1.");
    assert_false(claim3.overlaps_with(claim2), "Should not overlap with Claim 2.");
}

int main()
{
    RUN_TESTS(test_basic);
    RUN_TESTS(test_overlaps_with);
}
