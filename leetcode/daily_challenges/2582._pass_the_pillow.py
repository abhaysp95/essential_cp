#!/usr/bin/env python3

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        if time < n:
            return time + 1
        rounds_passed = time // (n - 1)
        time -= (rounds_passed * (n - 1))
        if rounds_passed & 1 and time == 0:
            return n
        elif rounds_passed & 1:
            return n - time
        else:
            return time + 1

def main():
    line = input().split(" ")
    # first input n
    n = int(line[0])
    # second input time
    time = int(line[1])
    solve = Solution()
    print(solve.passThePillow(n, time))

if __name__ == "__main__":
    main()
