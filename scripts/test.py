import sudoku.solver.cpp
import pprint

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0, 9, 3, 0],
        [0, 0, 0, 0, 0, 0, 7, 0, 0],
        [0, 0, 8, 0, 0, 9, 2, 4, 6],
        [8, 5, 0, 0, 0, 0, 6, 2, 4],
        [3, 0, 6, 0, 5, 0, 1, 9, 7],
        [2, 0, 1, 4, 0, 0, 0, 0, 3],
        [0, 0, 5, 0, 9, 0, 3, 0, 2],
        [9, 2, 3, 7, 8, 0, 4, 0, 1],
        [6, 7, 0, 3, 0, 1, 0, 0, 9]
    ]
    print("CPP")
    sudoku.solver.cpp.solve(grid, 3)
    pprint.pprint(grid)
