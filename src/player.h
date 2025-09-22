// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_PLAYER_H_
#define MANATOM_PLAYER_H_

#include <stdint.h>

#include "inventory.h"

static einv* player_inv = {};
static compound player_compound = {};
static uint8_t player_cup = 0;

void make_player_inv();

#endif
