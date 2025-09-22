// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "command.h"
#include "compound.h"
#include "inventory.h"
#include "world.h"

void print_help() {
  printf("\
Manatom - a game where you manage your atoms\n\
Commands:\n\
  \n\
  help - print this help screen\n\
  \n\
  inv - print your inventory\n\
  \n\
  inspect [object] - get information about the whole scene, or a specific\n\
                     object if you provide the name\n\
  \n\
  use <object> - use an object\n\
  \n\
  talk <person> - talk to somebody\n\
  \n\
  quit | exit - exit the game\n\
  \n\
NOTE:\n\
You may get to a point where you are STUCK\n\
and CAN NOT CONTINUE.\n\
To restart, simply exit the game and open\n\
it again.\n\
\n\
");
}

void get_input(char* buf, size_t s) {
  printf("\n> ");
  fgets(buf, s, stdin);
}

char* get_params(char* cmd) {
  char* ptr = cmd;
  while (1) {
    if (*ptr == '\0') return ptr;
    if (*ptr == ' ') return ptr + 1;
    ptr++;
  }
  return ptr;
}

uint8_t do_cmd(char* cmd) {
  if (IF_CMD(cmd, "help")) {
    print_help();
    return 0;
  }
  else if (IF_CMD(cmd, "inv")) {
    print_player_inv();
    return 0;
  }
  else if (IF_CMD(cmd, "inspect")) {
    cmd_inspect(get_params(cmd));
    return 0;
  }
  else if (IF_CMD(cmd, "use")) {
    cmd_use(get_params(cmd));
    return 0;
  }
  else if (IF_CMD(cmd, "talk")) {
    return cmd_talk(get_params(cmd));
  }
  else if (IF_CMD(cmd, "exit") || IF_CMD(cmd, "quit")) {
    return 1;
  }
  printf("Unknown command %s", cmd);
  return 0;
}

uint8_t cmd_talk(char* param) {
  if (IF_CMD(param, "boy")) return boy_talk();
  else if (IF_CMD(param, "man")) man_talk();
  else if (IF_CMD(param, "cake") || IF_CMD(param, "candle"))
		printf("... It says nothing.\n");
  else if (IF_CMD(param, "window"))
		printf("... It says nothing.\n");
  else if (IF_CMD(param, "presents"))
		printf("... It says nothing.\n");
  else if (IF_CMD(param, "balloons"))
		printf("... It says nothing.\n");
  else printf("Invalid parameter %s\n", param);
  return 0;
}

void cmd_inspect(char* param) {
  if (IF_CMD(param, "boy")) boy_inspect();
  else if (IF_CMD(param, "man")) man_talk();
  else if (IF_CMD(param, "cake") || IF_CMD(param, "candle")) cake_inspect();
  else if (IF_CMD(param, "window")) window_inspect();
  else if (IF_CMD(param, "presents")) presents_inspect();
  else if (IF_CMD(param, "balloons")) balloons_inspect();
  else
    printf("\
Things to inspect:\n\
- boy\n\
- man\n\
- cake\n\
- presents\n\
- balloons\n\
- window\n\
");
}

void cmd_use(char* param) {
  if (IF_CMD(param, "boy")) boy_use();
  else if (IF_CMD(param, "man")) man_talk();
  else if (IF_CMD(param, "cake") || IF_CMD(param, "candle")) cake_use();
  else if (IF_CMD(param, "window")) window_use();
  else if (IF_CMD(param, "presents")) presents_use();
  else if (IF_CMD(param, "balloons")) balloons_use();
  else printf("Invalid parameter %s\n", param);
}
