from cs50 import get_int

height = 0

while height < 1 or height > 8:
    height = get_int("Height: ")

spaces = height - 1
hashes = 1
for i in range(height):
    print(" " * spaces + "#" * hashes + "  " + "#" * hashes)
    hashes += 1
    spaces -= 1
