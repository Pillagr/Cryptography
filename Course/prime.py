from math import sqrt

def prime(number):
    num = int(number)
    if num%2 == 0:
        return False
    counter = 3
    while (counter < sqrt(num)):
        if num%counter == 0:
            return False
        counter+=2
    return True
            



if __name__ == "__main__":
    # num = 555
    # print(num, " ", prime(num))
    # num = 983
    # print(num, " ", prime(num))
    # num = 555
    # print(num, " ", prime(num))
    # num = 983
    # print(num, " ", prime(num))
    # num = 555
    # print(num, " ", prime(num))
    # num = 9823
    # print(num, " ", prime(num))
    # num = 833
    # print(num, " ", prime(num))
    # num = 983
    # print(num, " ", prime(num))
    # num = 7441
    # print(num, " ", prime(num))
    # num = 9973
    # print(num, " ", prime(num))
    # num = 555
    # print(num, " ", prime(num))
    # num = 983
    # print(num, " ", prime(num))
    # num = 1
    # print(num, " ", prime(num))
    # num = 999912
    # print(num, " ", prime(num))
    pass