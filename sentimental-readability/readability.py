from cs50 import get_string

def main()
    text = get_string("Text: ")

    letters = sum(c.isalpha() for c in text)
    words = text.count(" ") + 1
    sentences = text.count(".") + text.count("?") + text.count("!")

    
    index = 0.0588 * L - 0.296 * S - 15.8

main()
