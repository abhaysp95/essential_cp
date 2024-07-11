#!/usr/bin/env python3

from collections import deque
from typing import List

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = deque()
        new_str = []
        ca = 0 # count for alphabet only

        def rev_string(s: List[str], lo: int, hi: int):
            print(f"{s}, {lo}, {hi}")
            half = (hi - lo) // 2
            print(f"half: {half}")
            for i in range(half):
                temp = s[hi - i - 1]
                s[hi - i - 1] = s[lo + i]
                s[lo + i] = temp

        for c in s:
            if c == "(":
                stack.append(ca)
            elif c == ")":
                prev = stack.pop()
                # new_str[prev:ca] = new_str[prev:ca][::-1] # reverse the list
                rev_string(new_str, prev, ca)
            else: # getting alphabet here
                new_str.append(c)
                ca += 1
        return "".join(new_str)

def main():
    string = input()
    solve = Solution()
    print(solve.reverseParentheses(string))

if __name__ == "__main__":
    main()
