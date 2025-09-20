// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "element.h"

int main() {
  element h;
  set_atno(&h, 1);
  printf("%b, %i\n", is_tapped(h), get_atno(h));
  set_tapped(&h, true);
  printf("%b, %i\n", is_tapped(h), get_atno(h));
  return 0;
}
