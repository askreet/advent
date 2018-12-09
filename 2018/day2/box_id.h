#ifndef ADVENT_BOX_ID_H
#define ADVENT_BOX_ID_H

#include <string>
#include <iostream>

using namespace std;

class box_id
{
    friend ostream& operator<<(ostream& os, box_id& b);

public:
    box_id(string& id);
    box_id(string&& id);
    int difference_from(box_id b);
    string shared_characters_with(box_id b);

private:
    string id;
};

ostream& operator<<(ostream& os, box_id& b)
{
    os << b.id;
    return os;
}

box_id::box_id(string& id)
{
    this->id = id;
}

box_id::box_id(string&& id)
{
    this->id = id;
}

int box_id::difference_from(box_id b)
{
    int difference = 0;
    for (int i = 0; i < b.id.size(); i++) {
        if (b.id[i] != id[i]) difference++;
    }

    return difference;
}

string box_id::shared_characters_with(box_id b)
{
    string result;

    for (int i = 0; i < b.id.size(); i++) {
        if (b.id[i] == id[i])
            result += b.id[i];
    }

    return result;
}

#endif //ADVENT_BOX_ID_H
