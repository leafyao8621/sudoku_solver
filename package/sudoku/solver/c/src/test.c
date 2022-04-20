#include <stdio.h>
#include "core/core.h"

int main(void) {
    uint8_t grid[81] = {
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 9, 3, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, 7, EMPTY, EMPTY,
        EMPTY, EMPTY, 8, EMPTY, EMPTY, 9, 2, 4, 6,
        8, 5, EMPTY, EMPTY, EMPTY, EMPTY, 6, 2, 4,
        3, EMPTY, 6, EMPTY, 5, EMPTY, 1, 9, 7,
        2, EMPTY, 1, 4, EMPTY, EMPTY, EMPTY, EMPTY, 3,
        EMPTY, EMPTY, 5, EMPTY, 9, EMPTY, 3, EMPTY, 2,
        9, 2, 3, 7, 8, EMPTY, 4, EMPTY, 1,
        6, 7, EMPTY, 3, EMPTY, 1, EMPTY, EMPTY, 9
    };
    int ret = core_solve(grid, 3);
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
    for (uint8_t i = 0, *ii = grid; i < 9; ++i) {
        for (uint8_t j = 0; j < 9; ++j, ++ii) {
            printf("%3hhu", *ii & ~EMPTY);
        }
        putchar(10);
    }
    return 0;
}
