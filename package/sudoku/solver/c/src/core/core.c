#include "core.h"

int core_solve(uint8_t *grid, uint8_t size) {
    if (!grid) {
        return ERR_NULL_PTR;
    }
    if (!size || size > 20) {
        return ERR_INVALID_SIZE;
    }
    return 0;
}
