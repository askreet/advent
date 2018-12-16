//
// Created by kyle on 12/15/18.
//

#include <algorithm>
#include <optional>
#include "fabric_map.hh"
#include "fabric_claim.hh"

using namespace std;

fabric_map::fabric_map()
{

}

void fabric_map::add_claim(fabric_claim claim)
{
    claims.push_back(claim);

    for (int x = claim.x; x < claim.x+claim.width; x++) {
        for (int y = claim.y; y < claim.y+claim.height; y++) {
            pair<int, int> p(x, y);

            sqin_claims[p]++;
        }
    }
}


int fabric_map::total_overlapping_sq_inches()
{
    int total = 0;

    for (auto c : sqin_claims) {
        auto claim_count = c.second;

        if (claim_count > 1) {
            total++;
        }
    }

    return total;
}

optional<fabric_claim> fabric_map::find_unshared_claim()
{
    for (auto claim1 : claims) {
        auto is_not_overlapping = [&claim1](auto claim2) {
            if (claim1.id == claim2.id) {
                return true;
            }

            return !claim1.overlaps_with(claim2);
        };

        if (all_of(claims.begin(), claims.end(), is_not_overlapping)) {
            return claim1;
        };
    }

    return nullopt;
}
