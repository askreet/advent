#include <vector>
#include <fstream>
#include <iostream>
#include "box_id.h"

using namespace std;

int main()
{
    ifstream filestream;
    filestream.open("input.txt");

    vector<box_id> all_boxes;
    string line;
    while (getline(filestream, line)) {
        box_id new_box(line);

        for (auto box : all_boxes) {
            if (1 == new_box.difference_from(box)) {
                cout << "Box 1: " << box << endl;
                cout << "Box 2: " << new_box << endl;

                cout << "Shared Characters: " << new_box.shared_characters_with(box) << endl;
                return 0;
            }
        }

        all_boxes.push_back(new_box);
    }
}
