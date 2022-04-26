import sudoku.solver.c._base
import typing

def solve(grid: typing.List[int], size: int):
    """_summary_

    Args:
        grid (typing.List[int]): _description_
        size (int): _description_
    """
    sudoku.solver.c._base.solve(grid, size)
