#           01234567890123456789012345
alphabet = "abcdefghijklmnopqrstuvwxyz"
PT = "uyiiripmdrsvkyzzrelmslacb"
pt1 = "lmslacb"
key = {22, 9, 2}
def decode_block_shift(k):
    n = 22
    k = 9
    res = ""
    for idx, ch in enumerate(PT):
        c = (ord(ch)-97)
        c = chr(((c + n)%26) + 97)
        res += c
        if (idx%k) == (k-1):
            n+=1
            res += " "
    print(res)

def decode(msg, n):

    res = ""
    for ch in msg:
        c = (ord(ch)-97)
        c = chr(((c + n)%26) + 97)
        res += c
    print(res)




if __name__ == "__main__":
    for i in range(1, 25):
        decode(pt1, i)


