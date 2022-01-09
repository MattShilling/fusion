#include "reactions.h"

int Reactions::find_atom(Atom search, std::vector<Atom> &soup, size_t idx = 0) {
    for (size_t i = idx; i < soup.size(); i++) {
        if (soup[i].protons() == search.protons() &&
            soup[i].electrons() == search.electrons()) {
            return i;
        }
    }

    return -1;
}

double Reactions::deuterium_deuterium(std::vector<Atom> &soup) {
    int idx1 = find_atom(Deuterium, soup);
    int idx2 = find_atom(Deuterium, soup, idx1 + 1);

    if (idx1 == -1 && idx2 == -1) { return 0.0; }

    //
    soup.erase(soup.begin() + idx1);
    soup.erase(soup.begin() + idx2);

    std::random_device r;
    std::default_random_engine e1(r());
    // The D–D reaction actually has two branches, each occurring
    // with an approximately equal likelihood.
    std::uniform_int_distribution<int> uniform_dist(0, 1);
    int reaction_type = uniform_dist(e1);

    if (reaction_type == 0) {
        // D + D → He3 + n + 3.27 MeV.
        soup.push_back(Helium3);
        soup.push_back(Neutron);
        return 3.27 * MeV;
    } else {
        // D + D → T + p + 4.03 MeV.
        soup.push_back(Tritium);
        soup.push_back(Proton);
        return 4.03 * MeV;
    }
}