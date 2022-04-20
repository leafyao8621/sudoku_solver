#include <stdio.h>
#include "core/core.h"

int main(void) {
    uint8_t grid[16] = {
        EMPTY, 2, EMPTY, EMPTY,
        4, 3, 1, EMPTY,
        3, 1, EMPTY, EMPTY,
        2, EMPTY, 3, EMPTY
    };
    int ret = core_solve(grid, 4);
    if (ret) {
        switch (ret) {
        case ERR_NULL_PTR:
            puts("NULL_PTR");
            break;
        case ERR_INVALID_SIZE:
            puts("INVALID_SIZE");
            break;
        case ERR_NO_SOLUTION:
            puts("NO_SOLUTION");
            break;
        }
        return ret;
    }
    for (uint8_t i = 0, *ii = grid; i < 4; ++i) {
        for (uint8_t j = 0; j < 4; ++j, ++ii) {
            if (*ii & EMPTY) {
                printf("%s", "  _");
            } else {
                printf("%3hhu", *ii);
            }
        }
        putchar(10);
    }
    return 0;
}
