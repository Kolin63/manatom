// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "compound.h"
#include "element.h"
#include "inventory.h"

int main() {
  const char* world_symbols[] = { "H", "H", "H", "H", "H", "H", "H", "H", "He", "C", "O", "K", "Au" };
  const size_t world_size = sizeof(world_symbols) / sizeof(world_symbols[0]);
  element* world = make_world(world_symbols, world_size);

  printf("World: (%zi)\n", world_size);
  print_world(world, world_size);
  printf("\n\n");

  compound water[] = { &world[0], &world[1], &world[10] };
  print_compound(water, 3);
  printf("\n");

  while (true) {
    char input[64];
    get_input(input, 64);
    if (IF_CMD(input, "exit") || IF_CMD(input, "quit")) break;
  }

  free(world);

  return 0;
}
