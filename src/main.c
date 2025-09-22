// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>

#include "command.h"

int main() {
  printf("\nWelcome to Manatom. Type 'help' for a list of commands.\n");
  while (1) {
    char input[64];
    get_input(input, 64);
    if (do_cmd(input)) break;
  }

  return 0;
}
