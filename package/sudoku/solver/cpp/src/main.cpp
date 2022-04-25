#include <Python.h>
#include "core/core.h"

#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))

struct module_state {
    PyObject* error;
};

static PyObject* solve(PyObject* self, PyObject* args) {
    PyObject *grid_raw;
    long size;
    if (!PyArg_ParseTuple(args,
                          "O!l",
                          &PyList_Type, &grid_raw,
                          &size)) {
        return NULL;
    }
    std::vector<std::vector<Core::Slot> > grid;
    long width = size * size;
    grid.reserve(width);
    for (uint8_t i = 0; i < width; ++i) {
        grid.push_back(std::vector<Core::Slot>());
        grid[i].reserve(width);
        for (uint8_t j = 0; j < width; ++j) {
            long val =
                PyLong_AsLong(
                    PyList_GetItem(
                        PyList_GetItem(grid_raw, i), j
                    )
                );
            grid[i].push_back(Core::Slot(val == 0, val));
        }
    }
    try {
        Core::solve(grid, size);
    } catch (Core::Err err) {
        switch (err) {
        case Core::Err::ERR_INVALID_SIZE:
            PyErr_SetString(PyExc_RuntimeError, "ERR_INVALID_SIZE");
            return NULL;
        case Core::Err::ERR_NO_SOLUTION:
            PyErr_SetString(PyExc_RuntimeError, "ERR_NO_SOLUTION");
            return NULL;
        }
    }
    for (uint8_t i = 0; i < 9; ++i) {
        for (uint8_t j = 0; j < 9; ++j) {
            PyList_SetItem(
                PyList_GetItem(grid_raw, i),
                j,
                PyLong_FromLong(grid[i][j].get_value())
            );
        }
    }
    Py_RETURN_NONE;
}


static PyMethodDef _base_methods[] = {
    {"solve", (PyCFunction)solve, METH_VARARGS, NULL},
    {0}
};

static int _base_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->error);
    return 0;
}

static int _base_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->error);
    return 0;
}

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "sudoku.solver.cpp._base",
    NULL,
    sizeof(struct module_state),
    _base_methods,
    NULL,
    _base_traverse,
    _base_clear,
    NULL
};

PyMODINIT_FUNC PyInit__base(void) {
    PyObject *module = PyModule_Create(&moduledef);
    if (!module) return NULL;
    return module;
}
