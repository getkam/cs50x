from validator_collection import validators, errors


def main():
    try:
        validators.email(input("What's your email address?"))
        print("Valid")

    except (errors.EmptyValueError,errors.InvalidEmailError) :
        print("Invalid")

if __name__ == "__main__":
    main()
