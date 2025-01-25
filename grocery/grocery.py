def main():
    grocery_list = {}

    while True:
        try:
            item = input().strip().lower()
            if item in grocery_list:
                grocery_list[item] += 1
            else:
                grocery_list[item] = 1
        except EOFError:
            grocery_list = dict(sorted(grocery_list.items()))
            for i in grocery_list:
                print(f"{grocery_list[i]} {i.upper()}")
            break


main()
