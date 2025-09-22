// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>

#include "compound.h"
#include "element.h"

void print_compound(const compound c) {
  int amt = 0;
  const element* prev = c;

  for (size_t i = 0; c[i] != 0; i++) {
    if (*prev != c[i]) {
      printf("%s", get_symbol(*prev));
      if (amt > 1) printf("%i", amt);
      amt = 0;
    }
    amt++;
    prev = &c[i];
  }
  printf("%s", get_symbol(*prev));
  if (amt > 1) printf("%i", amt);
}
