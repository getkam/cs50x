def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if not(2<=len(s)<=6 and s[:1].isalpha() and s[1:2].isalpha()):
        return False
    numeric_started = False
    for i in s[2:]:
        if i.isalnum():
            if not numeric_started:
                if i.isnumeric():
                    if(i =='0'):
                        return False
                    numeric_started = True
            else:
                if i.isalpha():
                    return False
        else:
            return False
    return True



main()
