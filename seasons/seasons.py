from datetime import datetime, date, timedelta
import sys
import inflect

def main():
    birthday = get_user_birthday(input("Date of Birth: "))
    minutes = calculate_duration(birthday)
    print(say_number(minutes).capitalize())

def get_user_birthday(user_date):
    date_format = "%Y-%m-%d"
    try:
        if dt:=datetime.strptime(user_date, date_format):
            return dt.date()
        else:
            raise ValueError
    except ValueError:
        sys.exit("Invalid date")

def calculate_duration(from_date):
    duration = date.today() - from_date
    return duration.days * 24 * 60

def calculate_duration_minutes(from_date, to_date = date.today()):
    duration = to_date - from_date
    return duration.days * 24 * 60

def say_number(number):
    inf = inflect.engine()
    return inf.number_to_words(number, andword="") + " minutes"

if __name__ == "__main__":
    main()
