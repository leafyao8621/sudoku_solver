#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "core.h"

static inline void advance_iter(
    uint8_t *grid_end,
    uint8_t **iter
) {
    for (++(*iter); (*iter < grid_end) && !(**iter & EMPTY); ++(*iter));
}

static inline void retreat_iter(uint8_t *grid, uint8_t **iter) {
    for (--(*iter); (*iter >= grid) && !(**iter & EMPTY); --(*iter));
}

static inline bool check_position(
    uint8_t *grid,
    uint8_t size,
    uint8_t width,
    uint8_t *iter
) {
    static bool lookup[20];
    if (!(*iter & ~EMPTY)) {
        return false;
    }
    uint8_t offset = iter - grid;
    uint8_t row = offset / width;
    uint8_t col = offset % width;
    memset(lookup, 0, width);
    for (uint8_t i = 0, *ii = grid + row * width; i < width; ++i, ++ii) {
        if (*ii & ~EMPTY) {
            if (lookup[(*ii & ~EMPTY) - 1]) {
                return false;
            }
            lookup[(*ii & ~EMPTY) - 1] = true;
        }
    }
    memset(lookup, 0, width);
    for (uint8_t i = 0, *ii = grid + col; i < width; ++i, ii += width) {
        if (*ii & ~EMPTY) {
            if (lookup[(*ii & ~EMPTY) - 1]) {
                return false;
            }
            lookup[(*ii & ~EMPTY) - 1] = true;
        }
    }
    memset(lookup, 0, width);
    for (
        uint8_t i = 0,
        *ii = grid + row / size * size * width + col / size * size;
        i < size;
        ++i, ii += width - size
    ) {
        for (uint8_t j = 0; j < size; ++j, ++ii) {
            if (*ii & ~EMPTY) {
                if (lookup[(*ii & ~EMPTY) - 1]) {
                    return false;
                }
                lookup[(*ii & ~EMPTY) - 1] = true;
            }
        }
    }
    return true;
}

int core_solve(uint8_t *grid, uint8_t size) {
    if (!grid) {
        return ERR_NULL_PTR;
    }
    if (!size || size > 5) {
        return ERR_INVALID_SIZE;
    }
    uint8_t width = size * size;
    uint8_t *iter = grid;
    uint8_t *grid_end = grid + size * size * size * size;
    if (!(*iter & EMPTY)) {
        advance_iter(grid_end, &iter);
    }
    for (; iter < grid_end;) {
        for (
            ++(*iter);
            (*iter & ~EMPTY) <= width &&
            !check_position(grid, size, width, iter);
            ++(*iter)
        );
        if ((*iter & ~EMPTY) > width) {
            if (iter == grid) {
                return ERR_NO_SOLUTION;
            }
            *iter = EMPTY;
            retreat_iter(grid, &iter);
        } else {
            advance_iter(grid_end, &iter);
        }
    }
    return 0;
}
