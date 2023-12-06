#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @s: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *s)
{
    char *k;
    long int size, i, limit;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(s))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)(s))->ob_size;
    k = ((PyBytesObject *)s)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", k);

    if (size >= 10)
        limit = 10;
    else
        limit = size + 1;

    printf("  first %ld bytes:", limit);

    for (i = 0; i < limit; i++)
        if (k[i] >= 0)
            printf(" %02x", k[i]);
        else
            printf(" %02x", 256 + k[i]);

    printf("\n");
}

/**
 * print_python_list - Prints list information
 *
 * @s: Python Object
 * Return: no return
 */
void print_python_list(PyObject *s)
{
    long int size, i;
    PyListObject *k;
    PyObject *obj;

    size = ((PyVarObject *)(s))->ob_size;
    k = (PyListObject *)s;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", k->allocated);

    for (i = 0; i < size; i++)
    {
        obj = ((PyListObject *)s)->ob_item[i];
        printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
        if (PyBytes_Check(obj))
            print_python_bytes(obj);
    }
}
