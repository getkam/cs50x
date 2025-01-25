def main():
    fraction = get_fraction()
    print(gauge(fraction))

def get_fraction():
    while True:
        try:
            user_input = input("Fraction:")
            return convert(user_input)
        except(ValueError, ZeroDivisionError):
            continue

def convert(fraction):
    dividend, divisor = map(int, fraction.split("/"))

    if divisor == 0: raise ZeroDivisionError
    if dividend > divisor: raise ValueError

    quotient = (dividend / divisor) * 100
    return int(round(quotient,0))


def gauge(percentage):
    if not isinstance(percentage, int):
        raise ValueError
    if (percentage <= 1):
        return "E"
    elif (percentage >= 99):
        return "F"
    else:
        return f"{int(percentage)}%"

if __name__ == "__main__":
    main()
