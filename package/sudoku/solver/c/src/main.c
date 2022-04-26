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
    long width = size * size;
    long capacity = width * width;
    uint8_t *grid = malloc(capacity);
    for (uint8_t i = 0, *ii = grid; i < width; ++i) {
        for (uint8_t j = 0; j < width; ++j, ++ii) {
            long val =
                PyLong_AsLong(
                    PyList_GetItem(
                        PyList_GetItem(grid_raw, i), j
                    )
                );
            *ii = val ? val : EMPTY;
        }
    }
    int ret = core_solve(grid, size);
    if (ret) {
        switch (ret) {
        case ERR_INVALID_SIZE:
            PyErr_SetString(PyExc_RuntimeError, "ERR_INVALID_SIZE");
            break;
        case ERR_NO_SOLUTION:
            PyErr_SetString(PyExc_RuntimeError, "ERR_NO_SOLUTION");
            break;
        }
        free(grid);
        return NULL;
    }
    for (uint8_t i = 0, *ii = grid; i < 9; ++i) {
        for (uint8_t j = 0; j < 9; ++j, ++ii) {
            PyList_SetItem(
                PyList_GetItem(grid_raw, i),
                j,
                PyLong_FromLong(*ii & ~EMPTY)
            );
        }
    }
    free(grid);
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
    "sudoku.solver.c._base",
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
