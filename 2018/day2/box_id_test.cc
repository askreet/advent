#include <string>
#include "box_id.h"
#include "../libs/tests.h"

using namespace std;

void test_box_id_comparison()
{
    box_id box1("fghij");
    box_id box2("fguij");
    box_id box3("axcye");
    box_id box4("abcde");

    assert_true(1 == box1.difference_from(box2), "fghij should be only 1 different from fguij");
    assert_true(2 == box3.difference_from(box4), "axcye should be only 2 different from abcde");
}

void test_box_id_shared_characters()
{
    box_id box1("fghij");
    box_id box2("fguij");

    assert_equals(string("fgij"), box1.shared_characters_with(box2), "Should correctly determine shared characters.");
}

int main()
{
    RUN_TESTS(test_box_id_comparison)
    RUN_TESTS(test_box_id_shared_characters)
}
