//
// Created by kyle on 12/15/18.
//

#include "fabric_claim.hh"

#include <stdlib.h>
#include <regex>

fabric_claim::fabric_claim(string &string)
{
    smatch sm;
    regex_search(string, sm, regex("^#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)"));

    id = atoi(sm[1].str().c_str());
    x = atoi(sm[2].str().c_str());
    y = atoi(sm[3].str().c_str());
    width = atoi(sm[4].str().c_str());
    height  = atoi(sm[5].str().c_str());
}

bool fabric_claim::overlaps_with(fabric_claim other)
{
    return x < other.x+other.width &&
        x+width > other.x &&
        y < other.y+other.height &&
        y+height > other.y;
}
