// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_INVENTORY_H_
#define MANATOM_INVENTORY_H_

#include <stdint.h>

#include "compound.h"
#include "element.h"

typedef element einv;

void print_einv(const einv* i);
void clear_einv(einv* i);
void einv_add(einv* i, const element e);
uint8_t einv_remove(einv* i, const element e);
uint8_t einv_contains(const einv* i, const element e);
void sort_einv(einv* i);

#endif
