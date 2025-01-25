def main():
    while (True):
        fraction = input("Fraction:")
        try:
            dividend, divisor = map(int, fraction.split("/"))

            if divisor==0: raise ZeroDivisionError
            if dividend > divisor: raise ValueError

            quotient = (dividend / divisor)*100
            
        except (ValueError,ZeroDivisionError):
            continue
        else:
            quotient = round(quotient,0)

        if (quotient <= 1):
            print("E")
        elif (quotient >= 99):
            print("F")
        else:
            print(f"{int(quotient)}%")
        break

main()
