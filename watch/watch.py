import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    matches = re.search(r"^<iframe[^>]+?src=\"(http[s]?:\/\/(?:www\.)?youtube\.com\/embed\/\w+)\"[^>]*?><\/iframe>$", s, re.IGNORECASE)
    if matches:
        parsed = re.sub(r"http[s]?:\/\/(?:www\.)?youtube\.com\/embed\/", "https://youtu.be/", matches.group(1))
        return parsed

if __name__ == "__main__":
    main()
