#include <iostream>
#include "core/core.h"

int main() {
    uint8_t grid_raw[81] = {
        0, 0, 0, 0, 0, 0, 9, 3, 0,
        0, 0, 0, 0, 0, 0, 7, 0, 0,
        0, 0, 8, 0, 0, 9, 2, 4, 6,
        8, 5, 0, 0, 0, 0, 6, 2, 4,
        3, 0, 6, 0, 5, 0, 1, 9, 7,
        2, 0, 1, 4, 0, 0, 0, 0, 3,
        0, 0, 5, 0, 9, 0, 3, 0, 2,
        9, 2, 3, 7, 8, 0, 4, 0, 1,
        6, 7, 0, 3, 0, 1, 0, 0, 9
    };
    std::vector<std::vector<Core::Slot> > grid;
    grid.reserve(9);
    for (uint8_t i = 0, *ii = grid_raw; i < 9; ++i) {
        grid.push_back(std::vector<Core::Slot>());
        grid[i].reserve(9);
        for (uint8_t j = 0; j < 9; ++j, ++ii) {
            grid[i].push_back(Core::Slot(*ii == 0, *ii));
        }
    }
    try {
        Core::solve(grid, 3);
    } catch (Core::Err e) {
        switch (e) {
        case Core::Err::ERR_INVALID_SIZE:
            std::cout << "INVALID_SIZE\n";
            break;
        case Core::Err::ERR_NO_SOLUTION:
            std::cout << "NO_SOLUTION\n";
            break;
        }
        return 1;
    }
    for (uint8_t i = 0; i < 9; ++i) {
        for (uint8_t j = 0; j < 9; ++j) {
            std::cout << (int)grid[i][j].get_value() << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
