// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include <string.h>

#include "element.h"
#include "symbols.h"

element make_element(const char* symbol) {
  for (size_t i = 0; i <= ELEMENTS_AMT; i++) {
    if (strcmp(symbol, symbols[i]) == 0) return i;
  }
  return 0;
}

const char* get_symbol(const element e) {
  return symbols[e];
}

void print_element(const element e) {
  printf("%s", get_symbol(e));
}
