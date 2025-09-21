// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stddef.h>
#include <stdio.h>

#include "command.h"

void get_input(char* buf, size_t s) {
  printf("> ");
  fgets(buf, s, stdin);
}
