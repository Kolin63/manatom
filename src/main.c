// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "command.h"

int main() {
  while (1) {
    char input[64];
    get_input(input, 64);
    if (do_cmd(input)) break;
  }

  return 0;
}
