from pathlib import Path
from PIL import Image, ImageOps
import sys

def main():
    if (check_file_name(sys.argv)):
        try:
            with Image.open(sys.argv[1]) as img:
                with Image.open("shirt.png") as shirt:

                    resized = ImageOps.fit(img, shirt.size)
                    resized.paste(shirt, (0,0), shirt)
                    resized.save(sys.argv[2])

        except FileNotFoundError:
            sys.exit("Input does not exist")

def check_file_name(arguments):
    if (len(arguments) < 3):
        sys.exit("Too few command-line arguments")
    elif (len(arguments) > 3):
        sys.exit("Too many command-line arguments")
    else:
        valid_extensions = {".jpg", ".jpeg", ".png"}
        extension1 = Path(arguments[1]).suffix.lower()
        extension2 = Path(arguments[2]).suffix.lower()

        if extension1 not in valid_extensions: sys.exit("Invalid input")
        if extension2 not in valid_extensions: sys.exit("Invalid output")
        if extension1 != extension2: sys.exit("Input and output have different extensions")
    return True


if __name__ == "__main__":
    main()
