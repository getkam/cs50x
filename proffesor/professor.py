import random


def main():
    level = get_level()

    score = 0
    count_equation = 0

    while count_equation < 10:

        if (gen_equation(level) == True):
            score += 1

        count_equation += 1
        #print(f"Score: {score}")

    print(f"Score: {score}")

def gen_equation(level):
    attempt = 1
    num1 = generate_integer(level)
    num2 = generate_integer(level)
    while attempt <= 3:
        try:
            user_sum = int(input(f"{num1} + {num2} = "))
            if (user_sum == num1 + num2):
                return True
            else:
                print("EEE")
        except ValueError:
            print("EEE")
        attempt += 1

    print(f"{num1} + {num2} = {num1 + num2}")
    return False

def get_level():
    while True:
        try:
            level = int(input("Level:"))
            if level in [1, 2, 3]:
                return level
        except ValueError:
            continue

def generate_integer(level):
    if level not in [1, 2, 3]:
        raise ValueError
    if (level == 1):
        return random.randint(0, 9)
    elif (level == 2):
        return random.randint(10, 99)
    elif (level == 3):
        return random.randint(100, 999)


if __name__ == "__main__":
    main()
