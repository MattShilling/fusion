#pragma once

#include <vector>
#include <random>

#include "atom.h"

namespace Reactions {
// 
struct Product {
    std::vector<Atom> atoms;
    double energy;
};

int find_atom(Atom search, std::vector<Atom> &soup, size_t idx = 0) {
    for (size_t i = idx; i < soup.size(); i++) {
        if (soup[i].protons() == search.protons() && soup[i].electrons() == search.electrons()) {
            return i;
        }
    }

    return -1;

}

double deuterium_deuterium(std::vector<Atom> &soup) {
    int idx1 = find_atom(Deuterium, soup);
    int idx2 = find_atom(Deuterium, soup, idx1 + 1);

    if (idx1 == -1 && idx2 == -1) {
        return 0;
    }

    //
            soup[idx1].Consume();
        soup[idx2].Consume();

    std::random_device r;
    std::default_random_engine e1(r());
    // The D–D reaction actually has two branches, each occurring with an approximately equal likelihood.
    std::uniform_int_distribution<int> uniform_dist(0, 1);
    int reaction_type = uniform_dist(e1);

    if (reaction_type == 0) {
        // D + D → He3 + n + 3.27 MeV.
        soup.append()
    }



}


} // namespace Reactions
