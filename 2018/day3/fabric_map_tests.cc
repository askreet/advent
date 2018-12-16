#include "../libs/tests.h"
#include "fabric_map.hh"

void test_basic()
{
    fabric_map map;

    map.add_claim(fabric_claim(1, 1, 3, 4, 4));
    map.add_claim(fabric_claim(2, 3, 1, 4, 4));
    map.add_claim(fabric_claim(3, 5, 5, 2, 2));

    assert_equals(4, map.total_overlapping_sq_inches(), "Should overlap 4 inches.");
}

void test_finding_unshared_claim_when_all_overlap()
{
    fabric_map map;

    map.add_claim(fabric_claim(1, 1, 3, 4, 4));
    map.add_claim(fabric_claim(2, 3, 1, 4, 4));

    DESCRIBE("Map")
    assert_false(map.find_unshared_claim().has_value(), "Should not find unshared claim.");
}

void test_finding_unshared_claim()
{
    fabric_map map;

    map.add_claim(fabric_claim(1, 1, 3, 4, 4));
    map.add_claim(fabric_claim(2, 3, 1, 4, 4));
    map.add_claim(fabric_claim(3, 5, 5, 2, 2));

    DESCRIBE("Map")
    assert_equals(3, map.find_unshared_claim().value().id, "Should identify Claim 3 as unshared.");
}

int main()
{
    RUN_TESTS(test_basic)
    RUN_TESTS(test_finding_unshared_claim_when_all_overlap)
    RUN_TESTS(test_finding_unshared_claim)
}


