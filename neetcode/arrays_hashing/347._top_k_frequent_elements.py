import typing as ty
from collections import Counter
import heapq

class Solution:
    # QuickSelect:
    # There are two partitioning schemes:
    # Lomuto partitioning (used in index-based partitioning):
    # def partition(left, right):
    #     pivot = arr[right]
    #     i = left
    #     for j in range(left, right):
    #         if arr[j] < pivot:
    #             arr[i], arr[j] = arr[j], arr[i]
    #             i += 1
    #     arr[i], arr[right] = arr[right], arr[i]
    #     return i  # this is the final position of the pivot
    # Hoare's Paritioning (Swap-until-i-meets-j, often used in quick-sort):
    # i = left
    # j = right
    # pivot = arr[left]
    # while i < j:
    #     while i < j and arr[j] >= pivot:
    #         j -= 1
    #     while i < j and arr[i] <= pivot:
    #         i += 1
    #     arr[i], arr[j] = arr[j], arr[i]
    # We'll use index-based partitioning:
    # Index-based partition is like binary search, except the “key” is computed
    # by calling partition(), which rearranges the array and returns the index
    # where the pivot ended up. Everything smaller than the pivot goes before,
    # and bigger after. The returned index tells us how many elements are smaller
    # than the pivot — and that lets us zero in on the desired rank.
    # Best Solution
    def topKFrequentQuickSelect(self, nums: ty.List[int], k: int) -> ty.List[int]:
        freq_list: list[tuple[int, int]] = [(num, freq) for num, freq in Counter(nums).items()]
        # freq before the pivot_index will be less than the freq at pivot index
        # and after will be greater than or equal to pivot index
        # but here since it's freq it's going to be unique
        def partition(left: int, right: int) -> int: # return pivot index
            i: int = left
            pivot_freq: int = freq_list[right][1]
            for j in range(left, right):
                if freq_list[j][1] < pivot_freq:
                    freq_list[i], freq_list[j] = freq_list[j], freq_list[i]
                    i += 1
            freq_list[i], freq_list[right] = freq_list[right], freq_list[i]
            return i
        left: int = 0
        right: int = len(freq_list) - 1
        target = len(freq_list) - k # so, if k = 3, and n is 8, we need 5 smaller freq before
        while left <= right:
            pivot_index: int = partition(left, right)
            if pivot_index == target:
                return [num[0] for num in freq_list[target:]]
            elif pivot_index < target:
                left = pivot_index + 1
            else:
                right = pivot_index - 1
        return [] # shouldn't happen

    # Bucket Sort:
    # First we get the buckets lined up, generally it is n or n + 1
    # (depends on what we are putting, the numbers or the frequency, or something else).
    # Now, we need to work on the bucket. Sometimes it is needed, sometimes it is not.
    # Here we are not to going to operate on elements which we are going to put in bucket
    # and thus we would have O(n) time-complexity.
    def topKFrequentBucketSort(self, nums: ty.List[int], k: int) -> ty.List[int]:
        d: dict = Counter(nums)
        buckets: list[list[int]] = [[] for _ in range(len(nums))]
        for num, freq in d.items():
            buckets[freq-1].append(num)
        res: list[int] = []
        print(buckets)
        for b in buckets[::-1]:
            for n in b:
                res.append(n)
                if len(res) == k:
                    return res
        return res

    def topKFrequent(self, nums: ty.List[int], k: int) -> ty.List[int]:
        d: dict = Counter(nums)
        items: list[tuple[int, int]] = []
        res: list[int] = []
        for num, freq in d.items():
            heapq.heappush(items, (-freq, num))
        while k:
            res.append(heapq.heappop(items)[1])
            k -= 1
        return res

T = int(input())
while T:
    nums = list(int(x) for x in input()[1:-1].split(","))
    k = int(input())
    print(Solution().topKFrequentQuickSelect(nums, k))
    T -= 1
