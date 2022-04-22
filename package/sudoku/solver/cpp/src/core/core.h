#ifndef _CORE_H_
#define _CORE_H_

#include <cstdint>
#include <vector>

namespace Core {
    class Slot {
        bool empty;
        uint8_t value;
    public:
        Slot(bool empty, uint8_t value);
        bool get_empty();
        uint8_t get_value();
    };
    enum Err {
        ERR_INVALID_SIZE,
        ERR_NO_SOLUTION
    };
    void solve(std::vector<std::vector<Slot> > grid, uint8_t size);
}
#endif
