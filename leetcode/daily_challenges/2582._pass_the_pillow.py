#!/usr/bin/env python3

from abc import ABCMeta, abstractmethod

class Solution(metaclass=ABCMeta):
    @abstractmethod
    def passThePillow(self, n: int, time: int) -> int:
        return NotImplementedError

class SolutionMathBased(Solution):
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

class SolutionLoopBased(Solution):
    def passThePillow(self, n: int, time: int) -> int:
        idx, cidx, dir = 1, 1, 1
        while idx <= time:
            if dir == 1:
                cidx += 1
            else:
                cidx -= 1
            idx += 1
            if cidx == n:
                dir *= -1
        return cidx

def main():
    line = input().split(" ")
    # first input n
    n = int(line[0])
    # second input time
    time = int(line[1])
    solve = SolutionLoopBased()
    print(solve.passThePillow(n, time))

if __name__ == "__main__":
    main()
