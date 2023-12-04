#!/usr/bin/python3
def no_c(my_string):
    to_remove = C, c
    new_list =[ x for x in my_string if to_remove not in x]
    print(new_list)
