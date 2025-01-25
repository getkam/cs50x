def main():
    amount_due = 50
    allowed_coins = [25, 10, 5]

    while (amount_due >0):
        print(f"Amount Due: {amount_due}")
        coin = int(input("Insert a coin: "))
        if coin in allowed_coins :
            amount_due -= coin

    print(f"Change Owed: {amount_due * -1}")



main()
