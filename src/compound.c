// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "compound.h"
#include "element.h"

void print_compound(const compound c, const size_t s) {
  int amt = 0;
  const element* prev = &c[0];

  for (size_t i = 0; i <= s; i++) {
    if (get_atno(*prev) != get_atno(c[i])) {
      printf("%s", get_symbol(c[i - 1]));
      if (amt > 1) printf("%i", amt);
      amt = 0;
    }
    amt++;
    prev = &c[i];
  }
}
