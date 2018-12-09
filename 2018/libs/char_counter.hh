#include <stdio.h>
#include <string.h>

class CharCounter
{
public:
    CharCounter(const char* input);

    bool has_count_of(int count);

private:
    int counts[256];
};

CharCounter::CharCounter(const char* input)
{
    memset(this->counts, 0, sizeof(int[256]));

    for (int i = 0; input[i] != '\0'; i++) {
        counts[input[i]]++;
    }
}

bool CharCounter::has_count_of(int count)
{
    for (int i=0; i < 256; i++) {
        if (counts[i] == count) {
            return true;
        }
    }

    return false;
}
