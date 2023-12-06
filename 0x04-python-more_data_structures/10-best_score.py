#!/usr/bin/python3
def best_score(a_dictionary):
    if (a_dictionary):
        max = 0
        for s in a_dictionary:
            if a_dictionary[s] > max:
                max = a_dictionary[s]
            else:
                pass
        for s in a_dictionary:
            if a_dictionary[s] == max:
                return s
    return None
