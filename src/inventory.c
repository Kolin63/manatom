// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "element.h"

void print_einv(const einv* i) {
  const element* ptr = &i[0];
  for (size_t idx = 0; *ptr != 0; idx++) {
    print_element(*ptr);
    printf(" ");
    if ((idx + 1) % 10 == 0) printf("\n");
    ptr++;
  }
  if (&i[0] == ptr) printf("Empty.\n");
}
