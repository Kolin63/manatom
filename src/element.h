// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

// Aliases and functions for handling elements

#ifndef MANATOM_ELEMENT_H_
#define MANATOM_ELEMENT_H_

#include <stdint.h>

typedef uint8_t element;

#define ELEMENTS_AMT 118

element make_element(const char* symbol);
const char* get_symbol(const element e);

void print_element(const element e);

#endif
