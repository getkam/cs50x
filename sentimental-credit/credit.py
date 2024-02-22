from cs50 import get_s
import re

def main():
    ccnumber = 0
    while ccnumber > 0:
        ccnumber = get_int("Number: ")

    isValid = checkSum(ccnumber)

    re.match(ccnumber, [0-9]{13,15}


def checkSum(number):
    digit = 0
    remainingNo = number

    for index in range(len(number)):
        digit  = remainingNo % 10

        if index % 2 == 0:
            dd

        remainingNo = remainingNo / 10

    return True


main()
