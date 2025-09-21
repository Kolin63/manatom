// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_INVENTORY_H_
#define MANATOM_INVENTORY_H_

#include "compound.h"
#include "element.h"

typedef element* einv;
typedef compound* cinv;

element* make_world(const char* symbols, const size_t size);

void print_world(const element* i, const size_t s);
void print_einv(const einv* i, const size_t s);
void print_cinv(const cinv* i, const size_t s);

#endif
