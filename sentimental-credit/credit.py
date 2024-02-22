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
    pattern = r'^\d{13,16}$'
    begining2digits = str(number)[:2]
    if re.match(r'^\d{15}$', number) and (begining2digits == 34 or begining2digits == 37):
        print("AMEX")
    elif: re.match(r'^\d{15}$', number) and (begining2digits == 34 or begining2digits == 37)


main()
