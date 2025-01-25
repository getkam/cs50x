import random

def main():

    level = 0
    while True:
        try:
            level = int(input("Level:"))
            if (level > 0):
                break
        except ValueError:
            continue

    secret = random.randrange(1, level)

    while True:
        try:
            guess = int(input("Guess:"))
        except ValueError:
            continue

        if (secret > guess):
            print("Too small!")
        elif (secret < guess):
            print("Too large!")
        elif (secret == guess):
            print("Just right!")
            break



if __name__ == "__main__":
    main()
