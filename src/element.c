// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "element.h"

atno get_atno(const element e) {
  return e & 0x7f;
}

void set_atno(element* e, const atno a) {
  *e = (*e & 0x80) | a;
}

bool is_tapped(const element e) {
  return e >> 7;
}

void set_tapped(element* e, const bool t) {
  *e = get_atno(*e) | (t << 7);
}

const char* get_symbol(const element e) {
  return symbols[get_atno(e - 1)];
}

void print_element(const element e) {
  printf("%c%s", ' ' + is_tapped(e) * ('*' - ' '), get_symbol(e));
}
