// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compound.h"
#include "element.h"
#include "inventory.h"

int main() {
  const char* world_symbols[] = { "H", "He", "C", "O", "K" };
  const size_t world_size = sizeof(world_symbols) / sizeof(world_symbols[0]);
  element* world = make_world(*world_symbols, world_size);

  print_world(world, world_size);
  printf("\n\n");

  compound water[] = { &world[0], &world[3] };
  print_compound(water, 2);
  printf("\n");

  free(world);

  return 0;
}
