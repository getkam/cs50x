def main():
    fileName = input("File name:").strip().lower()

    if (fileName[-3:]=="jpg"):
        print("image/jpeg")
    elif (fileName[-4:]=="jpeg"):
        print("image/jpeg")
    elif (fileName[-3:]=="pdf"):
        print("application/pdf")
    elif (fileName[-3:]=="gif"):
        print("image/gif")
    elif (fileName[-3:]=="png"):
        print("image/png")
    elif (fileName[-3:]=="txt"):
        print("text/plain")
    elif (fileName[-3:]=="zip"):
        print("application/zip")
    else:
        print("application/octet-stream")


main()
