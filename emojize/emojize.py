import emoji

def main():

    user_input = input("Input:")
    print(emoji.emojize(f"Output: {user_input}", language='alias'))


main()
