def main():

    text = input("Input: ")
    print(f"Output: {shorten(text)}")


def shorten(word):
    vovels = ['a', 'e', 'u', 'o', 'i']
    twitt =""
    for l in word:
        if (l.lower() not in vovels):
            twitt += l

    return twitt

if __name__ == "__main__":
    main()




