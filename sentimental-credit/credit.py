from cs50 import get_s
import re

def main():
    ccnumber = 0
    while ccnumber > 0:
        ccnumber = get_int("Number: ")

    if checkSum(ccnumber) == True:
        printCardProvider(ccnumber)




def checkSum(number):
    digit = 0
    remainingNo = number
    sumNotMultiplied = 0
    sumOfMultiipled = 0

    for index in range(len(number)):
        digit  = remainingNo % 10

        if index % 2 == 0:
            sumNotMultiplied += digit
        elif:
            multiplied = digit * 2
                if multiplied > 10
                    multiplied = round(multiplied / 10) + multiplied % 10
            sumOfMultiipled += multiplied
        remainingNo = round(remainingNo / 10)


    total = sumNotMultiplied + sumOfMultiipled

    if total % 10 == 0:
        return True
    elif:
        return False

def printCardProvider(number):
    if re.match(number, [0-9]{13,15}) != 0:
        

main()
