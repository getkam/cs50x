from cs50 import get_string

def main()




def calculateLetters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

def calculateWords(text):
    return text.count(" ") + 1


def calculateSentences(text):
    return text.count(".") + text.count("?") + text.count("!")




main()
