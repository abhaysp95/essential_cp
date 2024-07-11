#!/usr/bin/env python3

from collections import deque
from typing import List

class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = deque()
        new_str = []
        ca = 0 # count for alphabet only

        for c in s:
            if c == "(":
                stack.append(ca)
            elif c == ")":
                prev = stack.pop()
                new_str[prev:ca] = new_str[prev:ca][::-1] # reverse the list
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
