// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "element.h"

element* make_world(const char* symbols[], const size_t size) {
  element* world = malloc(size);
  for (size_t i = 0; i < size; i++) {
    world[i] = make_element(symbols[i]);
  }
  return world;
}

void print_world(const element* i, const size_t s) {
  for (size_t idx = 0; idx < s; idx++) {
    print_element(i[idx]);
    printf(" ");
    if (idx + 1 % 10 == 0) printf("\n");
  }
}

void print_einv(const einv* i, const size_t s) {
  for (size_t idx = 0; idx < s; idx++) {
    print_element(*i[idx]);
    printf(" ");
    if (idx + 1 % 10 == 0) printf("\n");
  }
}

void print_cinv(const cinv* i, const size_t s) {

}
