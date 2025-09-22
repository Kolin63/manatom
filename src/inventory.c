// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "element.h"

void print_einv(const einv* i) {
  const element* ptr = &i[0];
  for (size_t idx = 0; i[idx] != 0; idx++) {
    print_element(i[idx]);
    printf(" ");
    if ((idx + 1) % 10 == 0) printf("\n");
    ptr++;
  }
  if (&i[0] == ptr) printf("Empty.\n");
}

void clear_einv(einv* i) {
  while (*i != 0) {
    *i = 0;
    i++;
  }
}

void einv_add(einv* i, element e) {
  size_t idx = 0;
  while (i[idx] != 0) idx++;
  i[idx] = e;
}

uint8_t einv_remove(einv* i, const element e) {
  size_t idx = 0;
  uint8_t found = 0;
  while (1) {
    if (i[idx] == 0) return 0;
    if (!found && i[idx] == e)
      found = 1;
    if (found)
      i[idx] = i[idx + 1];
    idx++;
  }
  return 1;
}

uint8_t einv_contains(const einv* i, const element e) {
  size_t idx = 0;
  while (i[idx] != 0) {
    if (i[idx] == e) return 1;
    idx++;
  }
  return 0;
}

int element_sort(const void* a, const void* b) {
  element elem_a = *((element*)a);
  element elem_b = *((element*)b);

  if (elem_a == elem_b) return 0;
  else if (elem_a > elem_b) return 1;
  else return -1;
}

void sort_einv(einv* i) {
  size_t s = 0;
  element* ptr = &i[0];
  while (*ptr != 0) {
    s++;
    ptr++;
  }
  qsort(i, s, 1, element_sort);
}
