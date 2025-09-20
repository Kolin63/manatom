// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "compound.h"
#include "element.h"

int main() {
  element h;
  set_atno(&h, 1);
  print_element(h);
  printf("\n");
  set_tapped(&h, true);
  print_element(h);
  printf("\n");

  element h2;
  set_atno(&h2, 1);
  set_tapped(&h2, true);
  element o;
  set_atno(&o, 8);
  set_tapped(&o, true);

  compound water[] = { &h, &h2, &o };
  print_compound(*water, 3);
  printf("\n");

  return 0;
}
