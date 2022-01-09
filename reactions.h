#pragma once

#include <vector>

#include "atom.h"

namespace Reactions {
// 
struct Product {
    std::vector<Atom> atoms;
    double energy;
};




} // namespace Reactions
