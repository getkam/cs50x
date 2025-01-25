from numb3rs import validate

def main():
    test_validate_positive()
    test_validate_negative()

def test_validate_positive():
    assert validate("192.168.0.1") == True
    assert validate("10.0.0.254") == True
    assert validate("172.16.100.100") == True
    assert validate("203.0.113.42") == True
    assert validate("8.8.8.8") == True
    assert validate("255.100.50.25") == True

def test_validate_negative():
    assert validate("192.168.1.300") == False
    assert validate("192.168.1.1.1") == False
    assert validate("192.168.1") == False
    assert validate("192.168.-1.1") == False

if __name__ == "__main__":
    main()
