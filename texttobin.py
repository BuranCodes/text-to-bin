# Buran
# Quick conversion of text to binary
def txtbin(txt):
    bintxt = ""
    for char in txt:
        tmp = ""
        bc = ord(char)
        while bc != 0:
            if (bc%2 == 0):
                tmp += "0"
            elif (bc%2 == 1):
                tmp += "1"
            bc = int(bc/2)
        if len(tmp) != 8:
            for x in range(8-len(tmp)):
                tmp += "0" # add leading zeroes
        bintxt += tmp + " "
    bintxt = bintxt[::-1] # reverse the order
    bintxt = " ".join(reversed(bintxt.split(" ")))
    # flip binary text to the other way
    print(f"The resulting binary of said text is: {bintxt}")


txt = input("Enter any text to convert into binary: ")
txtbin(txt)
