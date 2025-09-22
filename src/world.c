// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stdio.h>
#include "compound.h"
#include "element.h"
#include "inventory.h"

#include "world.h"

static einv player_inv[32] = {0};
static uint8_t player_is_compound = 0;

static uint8_t window_used = 0;
static uint8_t has_cup = 0;
static uint8_t balloons_used = 0;

static uint8_t boy_talked = 0;
static uint8_t man_talked = 0;

void print_player_inv() {
  if (player_is_compound == 0) {
    print_einv(player_inv);
  }
  else {
    print_compound(player_inv);
  }
  if (has_cup) printf("(you have a cup)\n");
}

void boy_inspect() {
  printf("The birthday boy.\nHe seems upset\n");
}

void boy_use() {
  printf("You really shouldn't dehumanize a person like that.\n");
}

void boy_talk() {
  if (boy_talked == 0) {
    boy_talked = 1;
    printf("\
Birthday is ruined!\n\
Because of my thirst\n\
Please, bring me a drink\n\
So it's not the worst.\n\
(wow, what a beautiful poem)\n\
    ");
  }
  else {
    printf("TODO\n");
  }
}

void man_inspect() {
  printf("A man standing in the corner.\n\
He seems like he'd be willing to make a deal.\n\
");
}

void man_use() {
  printf("You really shouldn't dehumanize a person like that.\n");
}

void man_talk() {
  if (man_talked == 0 || !einv_contains(player_inv, 50)) {
    man_talked = 1;
    printf("\
Hey. Need a cup?\n\
Well, if you bring me a tin atom, I can make a\n\
tin cup for you.\n\
");
  }
  else if (einv_contains(player_inv, 50)) {
    printf("\
Ha! You think *that's* tin!?\n\
What you have there is Aluminium! (he's British)\n\
\n\
You know, tin foil is actually made of aluminium.\n\
It's just been a common misconception since the start\n\
of time that it's made of tin.\n\
\n\
No matter, I can make you an aluminium cup.\n\
(You get a cup)\n\
");
    has_cup = 1;
    einv_remove(player_inv, 50);
  }
  else {
    printf("How's that cup faring you?\n");
  }
}

void cake_inspect() {
  printf("\
Upon further inspection, the cake seems to be a lie.\n\
In place of the sugary sweet that you were inspecting,\n\
you find a tank of propane.\n\
On top of the tank are ten 'candles' that are emitting flames.\n\
  ");
}

void cake_use() {
  if (*player_inv == 0) {
    printf("You could use the candles if you had some atoms...\n");
    return;
  }
  else if (player_is_compound) {
    printf("You have already made a compound with the candles!\n");
    return;
  }
  else {
    einv_add(player_inv, 8);
    sort_einv(player_inv);
    player_is_compound = 1;
    printf("\
You hold all of your elements atop the candle...\n\
The sparks from the candle fuse the elements, as well\n\
as one oxygen from the atmosphere, into a compound\n\
\n\
(You get a ");
    print_compound(player_inv);
    printf(")\n");
  }
}

void presents_inspect() {
  if (einv_contains(player_inv, 50) || has_cup) {
    printf("A stack of presents. One has it's wrapping removed.\n");
  }
  else {
    printf("A stack of presents. Oddly enough, one is wrapped in tin foil.\n");
  }
}

void presents_use() {
  if (!man_talked) {
    printf("You should probably leave these alone for now\n");
  }
  else if (has_cup) {
    printf("You leave the presents alone.\n");
  }
  else if (player_is_compound) {
    printf("Your hands are full with all this ");
    print_compound(player_inv);
    printf(".\n");
  }
  else if (einv_contains(player_inv, 50) || has_cup) {
    printf("You leave the presents alone.\n");
  }
  else {
    printf("\
You approach the presents, and notice that one of them is wrapped\n\
in tin foil. I guess they ran out of wrapping paper.\n\
\n\
You take off the wrapping, and see that the gift is a note.\n\
Taking a peek at the note, you see that it says,\n\
\n\
  Happy Birthday!\n\
  I didn't run out of wrapping paper, I just figured you\n\
  might need some tin foil.\n\
\n\
(You get 1 Tin)\n\
");
    einv_add(player_inv, 50);
  }
}

void window_inspect() {
  if (window_used == 0)
    printf("\
It's a nice sunny day. You notice that it's brighter than usual\n\
");
  else
    printf("It's a nice sunny day. You notice that it's\n\
not as bright as before.\
But that's ok, because at least you got to eject a\n\
neutron from an atom! You know, that's not something\n\
you get to do every day.\n\
");
}

void balloons_inspect() {
  if (!balloons_used)
    printf("\
There are two ballons floating in the corner.\n\
One is red, and one is blue. They seem full of helium.\n\
");
  else
    printf("\
The remnants of two balloons. The red and blue corpses\n\
lie on the ground.\n\
");
}

void balloons_use() {
  if (balloons_used)
    printf("Unfortunately, there's nothing left to do with these.\n");
  else {
    balloons_used = 1;
    printf("\
You draw your sword (because why would you not have a sword?)\n\
and gracefully penetrate the elastic surface of the balloons.\n\
\n\
(You get two helium)\n\
");
    einv_add(player_inv, 2);
    einv_add(player_inv, 2);
  }
}

void window_use() {
  if (window_used) printf("You enjoy the view.\n");
  else if (player_is_compound)
    printf("You enjoy the view. I'm sure some uncompounded atoms would\n\
like it too.\n\
");
  else if (*player_inv == 0)
    printf("You enjoy the view. I'm sure some atoms would like it too.\n");
  else {
    window_used = 1;
    element* ptr = player_inv;
    while (*ptr != 0) {
      *ptr = *ptr - 1;
      ptr++;
    }
    printf("\
As you stand at the window, it becomes noticeably warmer.\n\
Due to the fact that your cellular reception seems to have\n\
gotten worse, you assume that this was the result of a solar\n\
flare.\n\
\n\
Since solar flares are known to emit gamma rays, I wonder\n\
if this had any effect on your atoms?\n\
");
  }
}
