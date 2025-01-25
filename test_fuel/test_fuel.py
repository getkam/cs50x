from fuel import convert, gauge
import pytest

def main():
    test_convert()


def test_convert():
    assert convert("3/4") == 75
    assert convert("1/4") == 25
    assert convert("2/3") == 67
    assert convert("0/1") == 0
    assert convert("1/1") == 100


def test_convert_negative_ValueError():
    with pytest.raises(ValueError):
        convert("one/four")

def test_convert_negative_ZeroDiv():
    with pytest.raises(ZeroDivisionError):
        convert("1/0")

def test_gauge_positive():
    assert gauge(10) == "10%"
    assert gauge(0) == "E"
    assert gauge(1) == "E"
    assert gauge(2) == "2%"
    assert gauge(98) == "98%"
    assert gauge(99) == "F"
    assert gauge(101) == "F"

def test_gauge_negative_ValueError():
    with pytest.raises(ValueError):
        convert("ten")

if __name__ == "__main__":
    main()

