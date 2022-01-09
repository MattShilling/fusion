// Defines a class to represent an atom and makes a few static ones
// commonly used.

#pragma once

#include <cstdint>

class Atom {
  public:
    Atom(uint64_t electrons, uint64_t protons, uint64_t neutrons)
        : electrons_(electrons),
          protons_(protons),
          neutrons_(neutrons) {}

    uint64_t electrons() const noexcept {
        return electrons_;
    }

    uint64_t protons() const noexcept {
        return protons_;
    }

    uint64_t neutrons() const noexcept {
        return neutrons_;
    }

    bool Exists() {
        if (electrons_ > 0 || protons_ > 0 || neutrons_ > 0) {
            return true;
        }

        return false;
    }

    void Consume() {
        electrons_ = 0;
        protons_ = 0;
        neutrons_ = 0;
    }

    private:
    uint64_t electrons_;
    uint64_t protons_;
    uint64_t neutrons_;
};

// Hydrogen atoms.
static Atom Protium(1, 1, 0);
static Atom Deuterium(1, 1, 1);
static Atom Tritium(1, 1, 2);

// Helium atoms.
static Atom Helium2(2, 2, 0);
static Atom Helium3(2, 2, 1);
static Atom Helium4(2, 2, 2);
