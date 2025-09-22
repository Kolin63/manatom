// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_WORLD_H_
#define MANATOM_WORLD_H_

#include <stddef.h>

#include "element.h"
#include "inventory.h"

static const element ballons[] = {2, 2};
static const element presents[] = {13};

void boy_inspect();
void boy_use();
void boy_talk();

void cake_inspect();
void cake_use();

void presents_inspect();
void presents_use();

void balloons_inspect();
void balloons_use();

void window_inspect();
void window_use();

#endif
