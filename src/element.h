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

atno get_atno(const element e);
void set_atno(element *e, const atno a);

bool is_tapped(const element e);
void set_tapped(element *e, const bool t);

#endif
