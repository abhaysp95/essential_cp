cdt1 = input()
cdt2 = input()

pentagon = "ABCDE"
cdt1 = sorted(cdt1)
cdt2 = sorted(cdt2)

diff1 = pentagon.find(cdt1[1]) - pentagon.find(cdt1[0])
diff2 = pentagon.find(cdt2[1]) - pentagon.find(cdt2[0])

if diff1 == diff2:
    print("Yes")
else:
    print("No")
