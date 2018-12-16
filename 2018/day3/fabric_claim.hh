//
// Created by kyle on 12/15/18.
//

#ifndef PROJECT_FABRIC_CLAIM_HH
#define PROJECT_FABRIC_CLAIM_HH

#include <string>

using namespace std;

class fabric_claim
{
public:
    explicit fabric_claim(string& str);
    fabric_claim(int id, int x, int y, int width, int height)
        : id(id), x(x), y(y), width(width), height(height) {}

    int id;
    int x;
    int y;
    int width;
    int height;

    bool overlaps_with(fabric_claim claim);
};


#endif //PROJECT_FABRIC_CLAIM_HH
