from pathlib import Path
import sys
import csv


def main():
    file_name = get_file_name(sys.argv)
    file_content = get_file_content(file_name)
    write_into(file_content, sys.argv[2])

def write_into(content, file_name):
    with open(file_name, "w") as file:
        writer = csv.DictWriter(file, fieldnames = ["first", "last", "house"])
        writer.writeheader()
        for row in content:
            writer.writerow({"first": row["first"], "last": row["last"], "house": row["house"]})



def get_file_content(file_name):

    file_path = Path(file_name)

    if not file_path.exists():
        sys.exit("File does not exist")

    content = []
    with open(file_name) as file:
        reader = csv.DictReader(file)

        for row in reader:
            last, first = row["name"].split(",")
            content.append({"first": first.strip(), "last": last.strip(), "house": row["house"]})

    return content



def get_file_name(arguments):
    if (len(arguments) < 3):
        sys.exit("Too few command-line arguments")
    elif (len(arguments) > 3):
        sys.exit("Too many command-line arguments")
    else:
        if arguments[1][-4:] != ".csv":
            sys.exit("Not a CSV file")

    return arguments[1]


if __name__ == "__main__":
    main()
