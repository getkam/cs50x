from pyfiglet import Figlet
import sys

def main():
    font = "slant"
    if (len(sys.argv) == 3 and sys.argv[1] in ["-f","--f"]):
        font = sys.argv[2]
    elif (len(sys.argv) != 1):
        sys.exit("Invalid usage")

    user_input = input("Input:")
    figlet = Figlet(font = font)

    print(figlet.renderText(user_input))

main()
