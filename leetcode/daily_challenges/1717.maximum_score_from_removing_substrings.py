#!/usr/bin/env python3

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        score = 0
        firstc = 'a' if x > y else 'b'
        secondc = 'a' if x < y else 'b'
        i = 0
        new_s = s
        while i < len(new_s):
            found = False
            if new_s[i] == firstc and i + 1 < len(new_s):
                if new_s[i + 1] == secondc:
                    score += max(x, y)
                    s = s[0:i] + s[i + 2:] 
                    if i != 0:
                        i -= 1
                    found = True
            if not found:
                i += 1
            new_s = s
        i = 0
        new_s = s
        while i < len(new_s):
            found = False
            if new_s[i] == secondc and i + 1 < len(new_s):
                if new_s[i + 1] == firstc:
                    score += min(x, y)
                    s = s[0:i] + s[i + 2:] # replace ab
                    if i != 0:
                        i -= 1
                    found = True
            if not found:
                i += 1
            new_s = s
        return score

def main():
    inputs = input().split(" ")
    s, x, y = inputs
    solve = Solution()
    print(solve.maximumGain(s, int(x), int(y)))

if __name__ == "__main__":
    main()
