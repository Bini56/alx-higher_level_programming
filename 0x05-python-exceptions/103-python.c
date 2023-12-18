#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *other)
{
    char *str;
    long int size, i, limit;

    setbuf(stdout, NULL);

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(other))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        setbuf(stdout, NULL);
        return;
    }

    size = ((PyVarObject *)(other))->ob_size;
    str = ((PyBytesObject *)other)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    if (size >= 10)
        limit = 10;
    else
        limit = size + 1;

    printf("  first %ld bytes:", limit);

    for (i = 0; i < limit; i++)
    {
        if (str[i] >= 0)
            printf(" %02x", str[i]);
        else
            printf(" %02x", 256 + str[i]);
    }

    printf("\n");
    setbuf(stdout, NULL);
}

/**
 * print_python_float - Prints float information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_float(PyObject *other)
{
    double val;
    char *nf;

    setbuf(stdout, NULL);
    printf("[.] float object info\n");

    if (!PyFloat_Check(other))
    {
        printf("  [ERROR] Invalid Float Object\n");
        setbuf(stdout, NULL);
        return;
    }

    val = ((PyFloatObject *)(other))->ob_fval;
    nf = PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, Py_DTST_FINITE);

    printf("  value: %s\n", nf);
    setbuf(stdout, NULL);
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *other)
{
    long int size, i;
    PyListObject *lst;
    PyObject *obj;

    setbuf(stdout, NULL);
    printf("[*] Python list info\n");

    if (!PyList_Check(other))
    {
        printf("  [ERROR] Invalid List Object\n");
        setbuf(stdout, NULL);
        return;
    }

    size = ((PyVarObject *)(other))->ob_size;
    lst = (PyListObject *)other;

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", lst->allocated);

    for (i = 0; i < size; i++)
    {
        obj = lst->ob_item[i];
        printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);

        if (PyBytes_Check(obj))
            print_python_bytes(obj);
        if (PyFloat_Check(obj))
            print_python_float(obj);
    }
    setbuf(stdout, NULL);
}
