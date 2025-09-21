// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MANATOM_COMMAND_H_
#define MANATOM_COMMAND_H_

#include <stddef.h>

void get_input(char* buf, size_t s);

#define IF_CMD(input, cmd) !strncmp(input, cmd, strlen(cmd))

#endif
