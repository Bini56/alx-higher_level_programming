#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    from calculator_1 import add, sub, mul, div
    args = len(sys.argv)
    if(args != 4):
        print("Usage: ./100-my_calculator.py <a> <operator> <b>")
        exit(1)
    else:
        if((sys.argv[2]) in "+-*/"):
            a = int(sys.argv[1])
            b = int(sys.argv[3])
            if (sys.argv[2]) == '+':
                print("{} + {} = {}".format(a, b, add(a, b)))
                exit(0)
            elif (sys.argv[2]) == '-':
                print("{} - {} = {}".format(a, b, sub(a, b)))
                exit(0)
            elif (sys.argv[2]) == '*':
                print("{} * {} = {}".format(a, b, mul(a, b)))
                exit(0)
            else:
                print("{} / {} = {}".format(a, b, div(a, b)))
                exit(0)
        else:
            print("Unknown operator. Available operators: +, -, * and /")
            sys.exit(1)
