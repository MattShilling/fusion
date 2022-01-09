#pragma once

#include <random>
#include <vector>

#include "atom.h"
#include "units.h"

namespace Reactions {
//
struct Product {
    std::vector<Atom> atoms;
    double energy;
};

int find_atom(Atom search, std::vector<Atom> &soup, size_t idx = 0);

double deuterium_deuterium(std::vector<Atom> &soup);

}  // namespace Reactions
