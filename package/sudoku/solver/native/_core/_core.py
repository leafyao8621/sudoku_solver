import typing

class Slot:
    def __init__(self, empty: bool, value: int):
        """_summary_

        Args:
            empty (bool): _description_
            value (int): _description_
        """
        self.empty = empty
        self.value = value
    def inc_value(self, width: int) -> bool:
        """_summary_

        Args:
            width (int): _description_

        Returns:
            bool: _description_
        """
        if (self.value == width):
            self.value = 0
            return False
        self.value += 1
        return True

def advance(
    grid: typing.List[typing.List[Slot]],
    width: int,
    limit: int,
    idx: int
) -> int:
    """_summary_

    Args:
        grid (typing.List[typing.List[Slot]]): _description_
        width (int): _description_
        limit (int): _description_
        idx (int): _description_

    Returns:
        int: _description_
    """
    idx += 1
    while (
        idx < limit and not grid[idx / width][idx % width].empty
    ):
        idx += 1
    return idx

def retreat(
    grid: typing.List[typing.List[Slot]],
    width: int,
    idx: int
) -> int:
    """_summary_

    Args:
        grid (typing.List[typing.List[Slot]]): _description_
        width (int): _description_
        idx (int): _description_

    Returns:
        int: _description_
    """
    idx -= 1
    while (
        idx >= 0 and not grid[idx / width][idx % width].empty
    ):
        idx -= 1
    return idx

def solve(grid: typing.List[typing.List[Slot]], size: int):
    """_summary_

    Args:
        grid (typing.List[typing.List[Slot]]): _description_
        size (int): _description_
    """
    pass
