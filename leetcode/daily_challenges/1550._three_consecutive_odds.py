#!/usr/bin/env python

from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        def is_odd(num: int) -> bool:
            if num & 1 == 1:
                return True
            return False

        if len(arr) < 3:
            return False
        for i in range(len(arr) - 2):
            if is_odd(arr[i]) and is_odd(arr[i + 1]) and is_odd(arr[i + 2]):
                return True

        return False

def main():
    arr = [int(x) for x in input()[1:][:-1].split(",")]
    solve = Solution()
    print(solve.threeConsecutiveOdds(arr))

if __name__ == "__main__":
    main()
