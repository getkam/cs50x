from plates import is_valid

def main():
    test_is_valid()

def test_is_valid_happy_flow():
    assert is_valid("AA") == True
    assert is_valid("ABCDEF") == True
    assert is_valid("CS50") == True
    assert is_valid("ABC123") == True
    assert is_valid("ABCDE1") == True

def test_is_valid_negative_lengh():
    assert is_valid("A") == False
    assert is_valid("1") == False
    assert is_valid("ABCD123") == False

def test_is_valid_negative_specials():
    assert is_valid(".CS50") == False
    assert is_valid("CS!50") == False
    assert is_valid("CS 50") == False
    assert is_valid("CS50?") == False

def test_is_valid_negative_zero():
    assert is_valid("CS05") == False
    assert is_valid("CC0") == False

def test_is_valid_negative_lack_two_letters():
    assert is_valid("A1") == False
    assert is_valid("A12345") == False
    assert is_valid("123") == False

def test_is_valid_negative_order():
    assert is_valid("AA1BCD") == False


if __name__ == "__main__":
    main()
