#include "core.h"

Core::Slot::Slot(bool empty, uint8_t value) {
    this->empty = empty;
    this->value = value;
}

void Core::solve(std::vector<std::vector<Slot> > grid, uint8_t size) {
    if (size > 5) {
        throw Core::Err::ERR_INVALID_SIZE;
    }
}
