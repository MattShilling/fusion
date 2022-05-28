// Matt Shilling 2022

#include <iostream>

#include "atom.h"
#include "reactions.h"

int main() {
    std::vector<Atom> soup = {Deuterium, Deuterium};

    double energy = Reactions::DeuteriumDeuterium::react(soup);
    double energy2 = Reactions::DeuteriumDeuterium::react(soup);

    std::cout << energy / MeV << std::endl;
    std::cout << energy2 / MeV << std::endl;
}