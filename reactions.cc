// Matt Shilling 2022

#include "reactions.h"

#include <vector>

static Atom pluck_atom(Atom search, std::vector<Atom> &soup) {
    Atom result(0, 0, 0);
    for (ssize_t i = 0; i < soup.size(); i++) {
        if (soup[i].protons() == search.protons() &&
            soup[i].electrons() == search.electrons()) {
            result = soup[i];
            soup.erase(soup.begin() + i);
            return result;
        }
    }

    return result;
}

static bool consume_atoms_if_all_exist(
    std::vector<Atom> atoms_to_consume,
    std::vector<Atom> &soup) {
    std::vector<Atom> plucked_atoms = {};
    for (Atom atom_to_consume : atoms_to_consume) {
        Atom result = pluck_atom(atom_to_consume, soup);
        if (!result.Exists()) {
            // We couldn't find the atom we're looking for, no point
            // in looking further.
            break;
        } else {
            plucked_atoms.push_back(result);
        }
    }

    bool consumed_all_atoms =
        plucked_atoms.size() == atoms_to_consume.size();

    if (!consumed_all_atoms) {
        // We were not able to pluck all the atoms from the soup
        // that we were instructed to consume. Put the atoms we
        // removed back into the soup.
        for (Atom atom_to_put_back : plucked_atoms) {
            soup.push_back(atom_to_put_back);
        }
    }

    return consumed_all_atoms;
}

double Reactions::DeuteriumDeuterium::react(
    std::vector<Atom> &soup) {
    double energy = 0.0;

    if (!consume_atoms_if_all_exist({Deuterium, Deuterium}, soup)) {
        return energy;
    }

    std::random_device r;
    std::default_random_engine e1(r());
    // The D–D reaction actually has two branches, each occurring
    // with an approximately equal likelihood.
    std::uniform_int_distribution<size_t> uniform_dist(
        FirstReactionBranch,
        LastReactionBranch);
    size_t reaction_type = uniform_dist(e1);

    switch (reaction_type) {
        case Helium3Reaction: {
            // D + D → He3 + n + 3.27 MeV.
            soup.push_back(Helium3);
            soup.push_back(Neutron);
            energy = 3.27 * MeV;
            break;
        }
        case TritiumReaction: {
            // D + D → T + p + 4.03 MeV.
            soup.push_back(Tritium);
            soup.push_back(Proton);
            energy = 4.03 * MeV;
        }
    }

    return energy;
}

double Reactions::DeuteriumHelium3::react(std::vector<Atom> &soup) {
    double energy = 0.0;

    if (!consume_atoms_if_all_exist({Deuterium, Helium3}, soup)) {
        return energy;
    }

    // D + He3 → alpha + p + 18.3 MeV.
    soup.push_back(Helium4);
    soup.push_back(Proton);
    energy = 18.3 * MeV;

    return energy;
}

double Reactions::DeuteriumTritium::react(std::vector<Atom> &soup) {
    double energy = 0.0;

    if (!consume_atoms_if_all_exist({Deuterium, Tritium}, soup)) {
        return energy;
    }

    // D + T → alpha + n + 17.6 MeV.
    soup.push_back(Helium4);
    soup.push_back(Neutron);
    energy = 17.6 * MeV;

    return energy;
}
