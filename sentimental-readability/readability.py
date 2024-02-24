from cs50 import get_string

def main()




def calculateLetters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

def calculateWords(text):
    count = 0
    for char in text:
        if char.isspace():
            count += 1
    count += 1 # for last word
    return count

def calculateSentences(text):
    count = 0
    


main()
