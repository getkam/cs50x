from cs50 import get_string
import re

def main():
    ccnumber = 0
    while ccnumber < 1:
        ccnumber = get_string("Number: ")

    if checkSum(ccnumber) == True:
        printCardProvider(ccnumber)
    else:
        print("INVALID")


def checkSum(number):
    digit = 0
    remainingNo = number
    sumNotMultiplied = 0
    sumOfMultiipled = 0

    for index in range(len(str(number))):
        digit  = remainingNo % 10

        if index % 2 == 0:
            sumNotMultiplied += digit
        else:
            multiplied = digit * 2
            if multiplied > 10:
                multiplied = round(multiplied / 10) + multiplied % 10
            sumOfMultiipled += multiplied
        remainingNo = round(remainingNo / 10)


    total = sumNotMultiplied + sumOfMultiipled

    if total % 10 == 0:
        return True
    else:
        return False

def printCardProvider(number):
    pattern = r'^\d{13,16}$'
    number = str(number)
    begining2digits = int(str(number)[:2])
    if re.match(r'^\d{15}$', number) and (begining2digits == 34 or begining2digits == 37):
        print("AMEX")
    elif (re.match(r'^\d{13}$', number) or re.match(r'^\d{16}$', number)) and round(begining2digits / 10) == 4:
        print("VISA")
    elif re.match(r'^\d{16}$', number) and (begining2digits >=51 and begining2digits <=55):
        print("MASTERCARD")
    else:
        print("INVALID")


main()
