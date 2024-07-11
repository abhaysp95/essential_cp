#!/usr/bin/env python3

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        remList = [0] * (n + 1)
        remCount = 0
        start = 1
        while remCount < n - 1:
            i, c = 0, start - 1
            while i <= k - 1:
                c += 1
                if c > n:
                    c = 1
                if remList[c] != -1:
                    i += 1
            remCount += 1
            remList[c] = -1
            if c < n and remList[c + 1] != -1:
                start = c + 1
            else:
                # get new start which is not used
                c += 1
                while True:
                    if c > n:
                        c = 1
                    if remList[c] == 0:
                        start = c
                        break
                    c += 1
        res = 0
        for i, x in enumerate(remList):
            if x == 0 and i != 0:
                res = i
                break
        return res

def main():
    line = input().split(" ")
    solve = Solution()
    print(solve.findTheWinner(int(line[0]), int(line[1])))

if __name__ == "__main__":
    main()
