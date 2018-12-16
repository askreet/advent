//
// Created by kyle on 12/15/18.
//

#ifndef PROJECT_FABRIC_MAP_HH
#define PROJECT_FABRIC_MAP_HH

#include <map>
#include <list>
#include "fabric_claim.hh"

using namespace std;

class fabric_map
{
public:
    void add_claim(fabric_claim claim);

    int total_overlapping_sq_inches();
    fabric_map();

    optional<fabric_claim> find_unshared_claim();

private:
    list<fabric_claim> claims;
    map<pair<int, int>, int> sqin_claims;
};

#endif //PROJECT_FABRIC_MAP_HH
