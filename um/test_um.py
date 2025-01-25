from um import count

def main():
    test_count()

def test_count_positive():
    assert count("um") == 1
    assert count("asd um, kaksj") == 1
    assert count("aswd hknnkjn nau") == 0
    assert count("hbhaduh um, aiojd um, iajshd kjjas um, jjss") == 3
    assert count("Um? Mum? Is this that album where, um, umm, the clumsy alums play drums?") == 2

def test_count_soecials():
    assert count("asd Um, kaksj") == 1
    assert count("Um, aswd hknnkjn nau") == 1
    assert count("hbhaduh um, aiojd um, iajshd kjjas um, jjss um") == 4

def test_count_inside():
    assert count("Yummy") == 0

if __name__ == "__main__":
    main()

