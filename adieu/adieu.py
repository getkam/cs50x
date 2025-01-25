def main():
    names = []
    while True:
        try:
            name = input("Name:")
            names.append(name)
        except EOFError:
            break

    goodbye = "Adieu, adieu, to "

    if (len(names)<1):
        sys.exit()
    elif (len(names) == 1):
        goodbye += names[0]
    elif (len(names) == 2):
        goodbye += " and ".join(names)
    elif (len(names) > 2):
        goodbye += ", ".join(names[:-1]) + ", and " + names[-1]

    print(goodbye)

main()
