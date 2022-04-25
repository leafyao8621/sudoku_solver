from setuptools import setup, Extension

solver_cpp_base = Extension('sudoku.solver.cpp._base',
                     sources=["sudoku/solver/cpp/src/core/core.cpp",
                              "sudoku/solver/cpp/src/main.cpp"])

# c_base = Extension('tree.c._base',
#                    sources=["tree/c/src/core/core.c",
#                             "tree/c/src/main.c"])

setup(name="tree",
      version="0.1",
      packages=["sudoku",
                "sudoku.solver",
                "sudoku.solver.cpp"],
      ext_modules=[solver_cpp_base])
