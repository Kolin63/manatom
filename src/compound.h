// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

// Aliases and functions for handling compounds

#ifndef MANATOM_COMPOUND_H_
#define MANATOM_COMPOUND_H_

#include <stddef.h>

#include "element.h"

typedef element compound[];

void print_compound(const compound* c);

#endif
