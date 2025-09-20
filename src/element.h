// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

// Aliases and functions for handling elements

#ifndef MANATOM_ELEMENT_H_
#define MANATOM_ELEMENT_H_

#include <stdbool.h>
#include <stdint.h>

// one element is 8 bits
// bit 8 is if the element is tapped
// bits 1 - 7 are atomic number
typedef uint8_t element;

// atomic number
// represents bits 1 - 7 of element
typedef uint8_t atno;

#define ELEMENTS_AMT 118

atno get_atno(const element e);
void set_atno(element *e, const atno a);

bool is_tapped(const element e);
void set_tapped(element *e, const bool t);

const char *get_symbol(const element e);

void print_element(const element e);

[[maybe_unused]]
static const char *symbols[ELEMENTS_AMT] = {
    "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na", "Mg",
    "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",  "Cr",
    "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf",
    "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po",
    "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm",
    "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs",
    "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og",
};

#endif
