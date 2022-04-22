#include <iostream>
#include "core.h"

Core::Slot::Slot(bool empty, uint8_t value) {
    this->empty = empty;
    this->value = value;
}

bool Core::Slot::get_empty() {
    return this->empty;
}

uint8_t Core::Slot::get_value() {
    return this->value;
}

bool Core::Slot::inc_value(uint8_t width) {
    if (this->value == width) {
        this->value = 0;
        return false;
    }
    ++(this->value);
    return true;
}

static void advance(
    std::vector<std::vector<Core::Slot> > &grid,
    uint8_t width,
    uint16_t limit,
    int16_t &idx
) {
    for (
        ++idx;
        idx < limit && !grid[idx / width][idx % width].get_empty();
        ++idx
    );
}

static void retreat(
    std::vector<std::vector<Core::Slot> > &grid,
    uint8_t width,
    int16_t &idx
) {
    for (
        --idx;
        idx >= 0 && !grid[idx / width][idx % width].get_empty();
        --idx
    );
}

static bool check(
    std::vector<std::vector<Core::Slot> > &grid,
    uint8_t size,
    uint8_t width,
    int16_t idx
) {
    uint8_t row = idx / width;
    uint8_t col = idx % width;
    std::vector<bool> lookup(width);
    std::fill(lookup.begin(), lookup.end(), false);
    for (uint8_t i = 0; i < width; ++i) {
        if (
            grid[row][i].get_value()
        ) {
            if (lookup[grid[row][i].get_value() - 1]) {
                return false;
            }
            lookup[grid[row][i].get_value() - 1] = true;
        }

    }
    std::fill(lookup.begin(), lookup.end(), false);
    for (uint8_t i = 0; i < width; ++i) {
        if (
            grid[i][col].get_value()
        ) {
            if (lookup[grid[i][col].get_value() - 1]) {
                return false;
            }
            lookup[grid[i][col].get_value() - 1] = true;
        }
    }
    std::fill(lookup.begin(), lookup.end(), false);
    for (
        uint8_t i = 0, ii = row / size * size;
        i < size;
        ++i, ++ii
    ) {
        for (
            uint8_t j = 0, jj = col / size * size;
            j < size;
            ++j, ++jj
        ) {
            if (
                grid[ii][jj].get_value()
            ) {
                if (lookup[grid[ii][jj].get_value() - 1]) {
                    return false;
                }
                lookup[grid[ii][jj].get_value() - 1] = true;
            }
        }
    }
    return true;
}
void Core::solve(std::vector<std::vector<Core::Slot> > &grid, uint8_t size) {
    if (size > 5) {
        throw Core::Err::ERR_INVALID_SIZE;
    }
    uint8_t width = size * size;
    uint16_t limit = width * width;
    int16_t idx = 0;
    if (!grid[0][0].get_empty()) {
        advance(grid, width, size, idx);
    }
    for (; idx < limit;) {
        for (
            ;
            grid[idx / width][idx % width].inc_value(width) &&
            !check(grid, size, width, idx);
        );
        if (grid[idx / width][idx % width].get_value()) {
            advance(grid, width, limit, idx);
        } else {
            if (idx) {
                retreat(grid, width, idx);
            } else {
                throw Core::Err::ERR_NO_SOLUTION;
            }
        }
    }
}
