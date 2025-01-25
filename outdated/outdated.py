MONTH = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

def main():

    while True:
        date = input("Date:").strip()

        if(date[0].isalpha()):
            try:
                month_name, day, year = date.split(' ')
            except ValueError:
                continue

            if (day[-1:]==','):
                day = int(day[0:-1])
            else:
                continue
            month = MONTH.index(month_name)+1
        elif(date[0].isdigit()):
            try:
                month, day, year = map(int, date.split('/'))
            except ValueError:
                continue

        if(0 <= day > 31 or 0 <= month > 12):
            continue

        print(f"{year}-{month:02}-{day:02}")
        break

main()
