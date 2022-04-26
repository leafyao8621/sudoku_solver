from setuptools import setup, Extension

solver_cpp_base = Extension('sudoku.solver.cpp._base',
                            sources=["sudoku/solver/cpp/src/core/core.cpp",
                                     "sudoku/solver/cpp/src/main.cpp"])

solver_c_base = Extension('sudoku.solver.c._base',
                          sources=["sudoku/solver/c/src/core/core.c",
                                   "sudoku/solver/c/src/main.c"])

setup(name="sudoku",
      version="0.1",
      packages=["sudoku",
                "sudoku.solver",
                "sudoku.solver.c",
                "sudoku.solver.cpp"],
      ext_modules=[solver_cpp_base, solver_c_base])
