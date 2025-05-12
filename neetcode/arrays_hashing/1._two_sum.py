import typing as ty

class Solution:
    def twoSum(self, nums: ty.List[int], target: int) -> ty.List[int]:
        tnums = [(x, i) for i, x in enumerate(nums)]
        tnums.sort(key=lambda tup: tup[0])
        i, j = 0, len(nums) - 1
        while i < j:
            if (sum := tnums[i][0] + tnums[j][0]) == target:
                return [tnums[i][1], tnums[j][1]]
            elif sum > target:
                j -= 1
            else:
                i += 1
        return []

T = int(input())
while T:
    nums = list(int(x) for x in input()[1:-1].split(","))
    target = int(input())
    T -= 1
    print(Solution().twoSum(nums, target))
