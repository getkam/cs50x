from bank import value

def main():
    test_value()

def test_value_happy_flow():
    assert value("hello") == 0

def test_value_staring_h():
    assert value("Hjsdhcj") == 20
    assert value("hjsdhcj") == 20

def test_value_negative():
    assert value("a") == 100
    assert value("1h") == 100
    assert value(".h") == 100

if __name__ == "__main__":
    main()

