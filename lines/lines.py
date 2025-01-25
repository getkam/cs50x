import sys
from pathlib import Path

def main():
    file_name = get_file_name(sys.argv)

    lines_count = count_lines(file_name)
    print(lines_count)

def count_lines(file):

    file_path = Path(file)
    if not file_path.exists():
        sys.exit("File does not exist")

    with open(file) as file:
        lines = file.readlines()

    counter = 0
    for line in lines:
        line = line.strip()

        if (len(line)>0 and line[0] != "#"):
            counter += 1
    return counter

def get_file_name(arguments):

    if (len(arguments) < 2):
        sys.exit("Too few command-line arguments")
    elif (len(arguments) > 2):
        sys.exit("Too many command-line arguments")
    else:
        if arguments[1][-3:] != ".py":
            sys.exit("Not a Python file")

    return arguments[1]

if __name__ == "__main__":
    main()
