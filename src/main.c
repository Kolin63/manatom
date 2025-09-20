// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "element.h"

int main() {
  element h;
  set_atno(&h, 1);
  print_element(h);
  printf("\n");
  set_tapped(&h, true);
  print_element(h);
  printf("\n");
  return 0;
}
