// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "player.h"

#include <stddef.h>
#include <stdlib.h>

void make_player_inv() {
  player_inv = malloc(0);
  player_inv_size = 0;
  player_cup = 0;
}
