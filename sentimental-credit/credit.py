from cs50 import get_string
import re

def main():
    ccnumber = ""
    while re.match(r'^\d{13,16}$', ccnumber) is None:
        ccnumber = get_string("Number: ")

    if checkSum(ccnumber) == True:
        printCardProvider(ccnumber)
    else:
        print("INVALID")


def checkSum(number):
    sumNotMultiplied = 0
    sumOfMultiipled = 0

    for index in range(len(number)):
        digit  = int(number[len(number) - 1 - index])
        print("digit:", digit, "index:", index)
        if index % 2 == 0:
            sumNotMultiplied += digit
        else:
            multiplied = digit * 2
            if multiplied > 10:
                sum = round(multiplied / 10) + multiplied % 10
            sumOfMultiipled += sum

    total = sumNotMultiplied + sumOfMultiipled
    print("total:", total)
    if total % 10 == 0:
        return True
    else:
        return False

def printCardProvider(number):
    pattern = r'^\d{13,16}$'
    begining2digits = number[:2]
    if re.match(r'^\d{15}$', number) and (begining2digits == '34' or begining2digits == '37'):
        print("AMEX")
    elif (re.match(r'^\d{13}$', number) or re.match(r'^\d{16}$', number)) and number[0] == '4':
        print("VISA")
    elif re.match(r'^\d{16}$', number) and (begining2digits >=51 and begining2digits <=55):
        print("MASTERCARD")
    else:
        print("INVALID")


main()
