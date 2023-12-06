#!/usr/bin/python3
def multiply_by_2(a_dictionary):
    if (a_dictionary):
        return(dict((i, j*2) for i, j in a_dictionary.items()))
