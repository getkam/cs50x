from seasons import calculate_duration_minutes, say_number, get_user_birthday
from datetime import date
import pytest

def main():
    test_seasons()

def test_get_user_birthday_positive():
    assert get_user_birthday("2000-01-01") == date(2000,1,1)

def test_get_user_birthday_negative():
    with pytest.raises(SystemExit):
        get_user_birthday("2000")
        get_user_birthday("Ala ma kota")
        get_user_birthday("January 1, 2000")


def test_calculate_duration_minutes():
    assert calculate_duration_minutes(date(2025, 1, 1), date(2025, 2, 1)) == 44640
    assert calculate_duration_minutes(date(1998, 6, 20), date(2000, 1, 1)) == 806400
    assert calculate_duration_minutes(date(2020, 6, 1), date(2032, 1, 1)) == 6092640
    assert calculate_duration_minutes(date(1999, 1, 1), date(2000, 1, 1)) == 525600

def test_say_number_positive():
    assert say_number(44640) == "forty-four thousand, six hundred forty minutes"
    assert say_number(806400) == "eight hundred six thousand, four hundred minutes"
    assert say_number(6092640) == "six million, ninety-two thousand, six hundred forty minutes"
    assert say_number(525600) == "five hundred twenty-five thousand, six hundred minutes"
    assert say_number(0) == "zero minutes"

if __name__ == "__main__":
    main()
