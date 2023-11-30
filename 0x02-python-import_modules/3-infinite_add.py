#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    sum = 0
    args = len(sys.argv)
    if(args <= 1):
        print(sum)
    elif(args >= 2):
        for x in range(1, args):
            sum += int(sys.argv[x])
        print(sum)
