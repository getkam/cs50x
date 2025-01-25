from pathlib import Path
from tabulate import tabulate
import sys
import csv

def main():
    file_name = get_file_name(sys.argv)
    menu = get_file_content(file_name)

    print(tabulate(menu, headers="keys", tablefmt ="grid"))


def get_file_content(file_name):
    file_path = Path(file_name)

    if not file_path.exists():
        sys.exit("File does not exist")
    menu = []
    with open(file_name) as file:
        reader = csv.DictReader(file)
        for item in reader:
            menu.append(item)

    return menu



def get_file_name(arguments):
    if (len(arguments) < 2):
        sys.exit("Too few command-line arguments")
    elif (len(arguments) > 2):
        sys.exit("Too many command-line arguments")
    else:
        if arguments[1][-4:] != ".csv":
            sys.exit("Not a CSV file")

    return arguments[1]


if __name__ == "__main__":
    main()
