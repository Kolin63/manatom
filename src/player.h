// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_PLAYER_H_
#define MANATOM_PLAYER_H_

#include <stdint.h>

#include "inventory.h"

static cinv* player_inv;
static size_t player_inv_size;
static uint8_t player_cup;

void make_player_inv();

#endif
