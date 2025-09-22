// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_COMMAND_H_
#define MANATOM_COMMAND_H_

#include <stddef.h>
#include <stdint.h>

void print_help();

void get_input(char* buf, size_t s);

#define IF_CMD(input, cmd) !strncmp(input, cmd, strlen(cmd))

// returns everything after first space
char* get_params(char* cmd);

// returns non zero if program should exit
uint8_t do_cmd(char* cmd);

void cmd_talk(char* param);
void cmd_inspect(char* param);
void cmd_use(char* param);

#endif
