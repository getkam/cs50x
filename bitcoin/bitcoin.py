import sys
import requests

def main():
    value = get_user_value()

    exchanged = exchange(value)
    if exchanged > 0:
        print(f"${(value * exchanged):,.4f}")
    else:
        sys.exit("")

def exchange(value):

    try:
        response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    except requests.RequestException:
        return -1

    coindesk_response = response.json()

    return coindesk_response["bpi"]["USD"]["rate_float"]


def get_user_value():
    if (len(sys.argv) < 2):
        sys.exit("Missing command-line argument")
    elif (len(sys.argv) > 2):
        sys.exit("Too many command-line arguments")
    else:
        try:
            user_value = float(sys.argv[1])
            return user_value
        except ValueError:
            sys.exit("Command-line argument is not a number")




if __name__ == "__main__":
    main()
