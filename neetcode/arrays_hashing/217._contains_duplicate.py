import typing as t

class Solution:
    def containsDuplicate(self, nums: t.List[int]) -> bool:
        d = {}
        for x in nums:
            if x not in d:
                d[x] = 0
            d[x] += 1
        for _, v in d.items():
            if v > 1:
                return True
        return False

T = int(input())
while T:
    l = list(int(x) for x in input()[1:-1].split(","))
    print(Solution().containsDuplicate(l))
    T -= 1
