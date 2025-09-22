// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>

#include "world.h"

void boy_inspect() {
  printf("The birthday boy.\nHe seems upset\n");
}

void boy_use() {
  printf("You really shouldn't dehumanize a person like that.\n");
}

void boy_talk() {
  printf("\
Birthday is ruined!\n\
Because of my thirst\n\
Please, bring me a drink\n\
So it's not the worst.\n\
(wow, what a beautiful poem)\n\
  ");
}

void cake_inspect() {
  printf("\
Upon further inspection, the cake seems to be a lie.\n\
In place of the sugary sweet that you were inspecting,\n\
you find a tank of propane.\n\
On top of the tank are ten 'candles' that are emitting flames.\n\
  ");
}
