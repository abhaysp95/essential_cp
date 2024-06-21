t = int(input())

while t > 0:
    n = int(input())
    s = input()

    res = ""
    i = n - 1
    while i > 0:
        temp = ""
        if s[i] != 'a' or s[i] != 'e':
            if i - 3 >= 0:
                temp = "." + s[i:i-3]
            else:
                temp = s[i::-1]
            i = i - 3
        else:
            if i - 2 >= 0:
                temp = "." + s[i:i-2]
            else: temp = s[i::-1]
            i = i - 2
        res = temp + res

    print(res)

    t -= 1
