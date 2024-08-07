#!/usr/bin/env python3

from abc import ABCMeta, abstractmethod
from typing import List
from bisect import bisect_left, bisect_right

# Solution interface
class Solution(metaclass = ABCMeta):
    @abstractmethod
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return NotImplementedError


# trying to optimize
class OptimizedSolution(Solution):
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # sort the array
        nums1.sort()
        nums2.sort()

        res, lst, gst = [], [], []
        if (len(nums1) != len(nums2)):
            lst = nums1 if len(nums1) < len(nums2) else nums2
            gst = nums1 if len(nums1) > len(nums2) else nums2
        else:
            lst, gst = nums1, nums2

        i = 0  # index for lst
        k = 0  # index fo gst
        while i < len(lst):
            # count lst[i] in  lst from given index
            lb = bisect_left(lst, lst[i], i)
            gb = bisect_right(lst, lst[i], i)
            c = gb - lb

            # get lower bound and upper bound to get range
            lb = bisect_left(gst, lst[i], k)
            gb = bisect_right(gst, lst[i], k)
            c2 = gb - lb
            k += c2

            for _ in range(min(c, c2)):
                res.append(lst[i])

            i += c
        return res

# initial approach
class OldSolution(Solution):
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res: List[int] = []
        for num in nums1:
            if num not in res:
                c1 = nums1.count(num)
                c2 = nums2.count(num)
                if c1 != 0 and c2 != 0:
                    for _ in range(min(c1, c2)):
                        res.append(num)

        return res

def main():
    lst1: List[int] = [int(x) for x in input()[1:][:-1].split(",")]
    lst2: List[int] = [int(x) for x in input()[1:][:-1].split(",")]
    solve: Solution = OptimizedSolution()
    print(solve.intersect(lst1, lst2))

if __name__ == "__main__":
    main()

# just for revision purpose
def lower_bound(nums: List[int], key: int, lo: int = 0, hi: int | None = None):
    if hi == None:
        hi = len(nums)
    hi -= 1

    while lo <= hi:
        mid = lo + ((hi - lo) // 2)
        if nums[mid] < key:
            lo = mid + 1
        elif nums[mid] >= key:
            hi = mid - 1
    return lo

def upper_bound(nums: List[int], key: int, lo: int = 0, hi: int | None = None):
    if hi == None:
        hi = len(nums)
    hi -= 1

    while lo <= hi:
        mid = lo + ((hi - lo) // 2)
        if nums[mid] <= key:
            lo = mid + 1
        elif nums[mid] > key:
            hi = mid - 1
    return lo

