#!/usr/bin/python3
for i in range(10):
    for x in range(10):
        if(i == 8 and x == 9):
            print("{}".format(str(i) + str(j)))
        elif(x > i):
            print("{}".format(str(i) + str(j)) + ", ", end="")
