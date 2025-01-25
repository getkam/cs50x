from jar import Jar
import pytest

def main():
    test_jar()

def test_init():
    jar = Jar()
    assert jar.capacity == 12

def test_str():
    jar = Jar()
    jar.deposit(8)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪"

def test_deposit():
    jar = Jar()
    jar.deposit(6)
    assert jar.size == 6

def test_deposit_neg():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.deposit(13)

def test_withdraw():
    jar = Jar()
    jar.deposit(8)
    jar.withdraw(4)
    assert jar.size == 4

def test_withdraw_neg():
    jar = Jar()
    with pytest.raises(ValueError):
        jar.withdraw(1)
