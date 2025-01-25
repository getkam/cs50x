from twttr import shorten

def main():
    test_shorten()


def test_shorten_captalization():
    assert shorten("Warsaw") == "Wrsw"
    assert shorten("LONDON") == "LNDN"
    assert shorten("paris") == "prs"
    assert shorten("lIsbOn") == "lsbn"

def test_shorten_exclusive():
    assert shorten("qwrtyp") == "qwrtyp"
    assert shorten("aeoiu") == ""

def test_shorten_specials():
    assert shorten("pear! apple@#$%^^&*()<>?:.,;'banana") == "pr! ppl@#$%^^&*()<>?:.,;'bnn"
    assert shorten("") == ""

def test_shorten_numbers():
    assert shorten("1banana") == "1bnn"
    assert shorten("ban0ana") == "bn0n"
    assert shorten("banana3") == "bnn3"
    assert shorten("123") == "123"

if __name__ == "__main__":
    main()
