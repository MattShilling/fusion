// Matt Shilling 2022

#pragma once

#include <random>
#include <vector>

#include "atom.h"
#include "units.h"

namespace Reactions {

namespace DeuteriumDeuterium {
const size_t FirstReactionBranch = 0;
const size_t Helium3Reaction = 0;
const size_t TritiumReaction = 1;
const size_t LastReactionBranch = 1;
double react(std::vector<Atom> &soup);
}  // namespace DeuteriumDeuterium

namespace DeuteriumHelium3 {
const size_t FirstReactionBranch = 0;
const size_t Helium4Reaction = 0;
const size_t LastReactionBranch = 0;
double react(std::vector<Atom> &soup);
}  // namespace DeuteriumHelium3

namespace DeuteriumTritium {
const size_t FirstReactionBranch = 0;
const size_t Helium4Reaction = 0;
const size_t LastReactionBranch = 0;
double react(std::vector<Atom> &soup);
}  // namespace DeuteriumTritium

}  // namespace Reactions
