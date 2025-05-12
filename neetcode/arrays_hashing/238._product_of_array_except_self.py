import typing as ty

class Solution:
    # Intuition:
    # We can use the output array "res" as suffix array
    # and the input array "nums" as prefix array
    # we'll return the res after multiplying the values present in same indices
    def productExceptSelfBetterTimeAndSpaceComplexity(self, nums: ty.List[int]) -> ty.List[int]:
        res: list[int] = [] # suffix
        s: int = 1
        for x in nums[::-1]:
            res.append(s)
            s *= x
        res.reverse()
        nums = [1] + nums[:len(nums)-1] # prefix
        for i in range(1,len(nums)):
            nums[i] *= nums[i-1]
        for i in range(len(res)):
            res[i] *= nums[i]
        return res

    # Intuition:
    # prefix is array where the list will have multiplication of every element before it
    # prefix is array where the list will have multiplication of every element after it
    # example: [2, 3, 4, 5]
    # prefix: [1, 2, 2 * 3, 2 * 3 * 4] = [1, 2, 6, 24]
    # suffix: [3 * 4 * 5, 4 * 5, 5, 1] = [60, 20, 5, 1]
    # next you multiply the two array for same indices
    # because for each element in prefix you have multiplication of element before it and
    # in suffix you have for after the element, but none have for that element, so this works
    def productExceptSelfBetterTimeComplexity(self, nums: ty.List[int]) -> ty.List[int]:
        prefix: list[int] = []
        suffix: list[int] = []
        p: int = 1
        s: int = 1
        for x in nums:
            prefix.append(p)
            p *= x
        for x in nums[::-1]:
            suffix.append(s)
            s *= x
        suffix.reverse()
        return [x[0] * x[1] for x in zip(prefix, suffix)]

    def productExceptSelfBruteForce(self, nums: ty.List[int]) -> ty.List[int]:
        res: list[int] = []
        n = len(nums)
        for i in range(n):
            mul: int = 1
            for j in range(n):
                if i != j:
                    mul *= nums[j]
            res.append(mul)
        return res

T = int(input())
while T:
    arr = [int(x) for x in input()[1:-1].split(",")]
    print(Solution().productExceptSelfBetterTimeAndSpaceComplexity(arr))
    T -= 1
