#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include "fabric_map.hh"
#include "fabric_claim.hh"

using namespace std;

int main()
{
    ifstream filestream;
    filestream.open("input.txt");
    if (! filestream.is_open()) {
        cerr << "Failed to open input.txt!" << endl;
        exit(1);
    }

    fabric_map map;
    string line;

    while (getline(filestream, line)) {
        map.add_claim(fabric_claim(line));
    }

    cout << "Result: " << map.total_overlapping_sq_inches() << endl;

    return 0;
}
