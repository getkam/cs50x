from working import convert
import pytest

def main():
    test_convert()

def test_convert_positive():
    assert convert("9:00 AM to 5:00 PM") == "09:00 to 17:00"
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"
    assert convert("9:00 AM to 5 PM") == "09:00 to 17:00"
    assert convert("9 AM to 5:00 PM") == "09:00 to 17:00"
    assert convert("12:00 AM to 12:00 PM") == "00:00 to 12:00"

def test_convert_negative_range():
    with pytest.raises(ValueError):
         convert("0:00 AM to 5:00 PM")
         convert("20:00 AM to 5:00 PM")
         convert("0:80 AM to 5:00 PM")
         convert("9:00 AM to 13:00 PM")
         convert("9:00 AM to 12:61 PM")

def test_convert_negative_format():
    with pytest.raises(ValueError):
        convert("09:00 AM - 17:00 PM")
        convert("9 AM - 5 PM")

