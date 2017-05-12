#include "types.h"
#include "utils.h"
#include "killcount.h"
#include "fs.h"

void checkKillCount() {
    u8 count = getKillCount();

    switch (count) {
        case KILLCOUNT_INFINITE:
            break;
        case 0:
            mcuPowerOff();
            break;
        default:
            setKillCount(count - 1);
            break;
    }
}

u8 getKillCount() {
    u8 count;
    u32 num_read = fileRead(&count, KILLCOUNT_PATH, 1);

    if (num_read != 1) {
        return KILLCOUNT_INFINITE;
    } else {
        return count;
    }
}

void setKillCount(uint8_t count) {
    fileWrite(&count, KILLCOUNT_PATH, 1);
}
