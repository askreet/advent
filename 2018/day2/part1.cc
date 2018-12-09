#include <iostream>
#include <fstream>
#include <stdio.h>
#include "../libs/char_counter.hh"

using namespace std;

int main()
{
    ifstream filestream;
    filestream.open("input.txt");

    int two_occur = 0;
    int three_occur = 0;

    string line;
    while (getline(filestream, line)) {
        cout << "Got line: " << line << endl;
        CharCounter cc(line.c_str());
        if (cc.has_count_of(2)) two_occur++;
        if (cc.has_count_of(3)) three_occur++;
    }

    cout << "Result: " << two_occur * three_occur << endl;

    return 0;
}
