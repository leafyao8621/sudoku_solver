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
        friend void solve(std::vector<std::vector<Slot> > grid, uint8_t size);
    };
    enum Err {
        ERR_INVALID_SIZE,
        ERR_NO_SOLUTION
    };
    void solve(std::vector<std::vector<Slot> > grid, uint8_t size);
}
#endif
