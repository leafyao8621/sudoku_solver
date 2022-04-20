#ifndef _CORE_H_
#define _CORE_H_

#include <stdint.h>

#define EMPTY 0x80

#define ERR_NULL_PTR 1
#define ERR_INVALID_SIZE 2
#define ERR_NO_SOLUTION 3

int core_solve(uint8_t *grid, uint8_t size);

#endif
