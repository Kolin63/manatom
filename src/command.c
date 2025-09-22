// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "command.h"
#include "inventory.h"
#include "player.h"

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
");
}

void get_input(char* buf, size_t s) {
  printf("> ");
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
    print_cinv(player_inv, player_inv_size);
    return 0;
  }
  else if (IF_CMD(cmd, "inspect")) {

  }
  else if (IF_CMD(cmd, "exit") || IF_CMD(cmd, "quit")) {
    return 1;
  }
  printf("Unknown command %s", cmd);
  return 0;
}
