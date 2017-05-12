#pragma once

#include "types.h"

#define KILLCOUNT_INFINITE 0xFF
#define KILLCOUNT_PATH "killcount.bin"

void checkKillCount();

u8 getKillCount();

void setKillCount(uint8_t count);
