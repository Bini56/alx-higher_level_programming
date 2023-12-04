#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    for x in matrix:
        for number in x:
            print("{:d}".format(number), end="")
            if(number is not x[len(x)-1]):
                print(" ", end="")
        print()
