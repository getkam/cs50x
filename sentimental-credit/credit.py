from cs50 import get_string
import re


def main():
    ccnumber = ""
    while re.match(r'^\d+$', ccnumber) is None:
        ccnumber = get_string("Number: ")

    if checkSum(ccnumber) == True:
        printCardProvider(ccnumber)
    else:
        print("INVALID")


def checkSum(number):
    sumNotMultiplied = 0
    sumOfMultiplied = 0

    for index in range(len(number)):
        digit = int(number[len(number) - 1 - index])
        if index % 2 == 0:
            sumNotMultiplied += digit
        else:
            multiplied = digit * 2
            sum = 0
            while multiplied >= 10:
                sum += multiplied % 10
                multiplied = int(multiplied / 10)
            sum += multiplied
            sumOfMultiplied += sum

    total = sumNotMultiplied + sumOfMultiplied
    if total % 10 == 0:
        return True
    else:
        return False


def printCardProvider(number):
    if re.match(r'^\d{15}$', number) and number[:2] in ['34', '37']:
        print("AMEX")
    elif re.match(r'^(\d{13}|\d{16})$', number) and number[0] == '4':
        print("VISA")
    elif re.match(r'^\d{16}$', number) and number[:2] in ['51', '52', '53', '54', '55']:
        print("MASTERCARD")
    else:
        print("INVALID")


main()
