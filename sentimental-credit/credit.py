from cs50 import get_s
import re

def main():
    ccnumber = 0
    while ccnumber > 0:
        ccnumber = get_int("Number: ")

    isValid = checkSum(ccnumber)

    re.match(ccnumber, [0-9]{13,15}


def checkSum(number):
    digit = number % 10
    remainingNo = number / 10

    for index in range(len(number)):
        if index % 2 == 0:
            #

    return True


main()
