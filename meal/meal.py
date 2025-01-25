def main():
    str = input("What time it is? ")


    parts = str.split(" ")

    time = convert(parts[0])

    if(len(parts)==2):
        if (parts[1] == "p.m."):
            time += 12

    if (time >= 7.0 and time < 8.0):
        print("breakfast time")
    elif (time >= 12.0 and time <= 13.0):
        print("lunch time")
    elif (time >= 18.0 and time < 19.0):
        print("dinner time")

def convert(time):
    hours, minutes = time.split(':')
    hours = int(hours)
    minutes = int(minutes)
    result = hours + minutes/60

    return round(result,2)


if __name__ == "__main__":
    main()
