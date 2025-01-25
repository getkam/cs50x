import re
import sys


def main():
    print(convert(input("Hours: ")))

def convert(s):
    first , second = s.split(" to ")
    return f"{convert_part(first)} to {convert_part(second)}"

def convert_part(str):

    findings = re.search(r"^(12|11|10|[0-9])(?::([0-5][0-9]))? [AP]M", str)
    if findings:
        hours = int(findings.group(1))
        if "PM" in str:
            hours+=12
            if  hours == 24 : hours = 12
        elif "AM" in str:
            if hours == 12: hours = 0
        minutes = findings.group(2)
        if minutes == None:
            minutes = "00"
        return f"{hours:02}:{minutes}"
    else:
        raise ValueError

if __name__ == "__main__":
    main()
