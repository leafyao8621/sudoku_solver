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
    uint16_t width,
    int16_t &idx
) {
    for (
        --idx;
        idx >= 0 && !grid[idx / width][idx % width].get_empty();
        --idx
    );
}

void Core::solve(std::vector<std::vector<Core::Slot> > grid, uint8_t size) {
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
        advance(grid, width, size, idx);
    }
}
