class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        s: set[int] = set(nums)
        mlen: int = 0
        # loop over hashset and not the list because if there are duplicates,
        # it'll have lots of redundant work
        # this will happen in case when there are lots of duplicate elements 
        # which are the root of connected component
        for x in s:
            # how to know that the element is start of the consecutive list ?
            # you check if x - 1 is present in the list or not. If not present, then it's start
            if x - 1 not in s:
                tlen: int = 1
                i: int = 1
                # check consecutively if element exists in list
                while x + i in s:
                    tlen += 1
                    i += 1
                mlen = max(mlen, tlen)
        return mlen

    def longestConsecutiveSorted(self, nums: list[int]) -> int:
        # puts unique elements one after another
        def remove_duplicate() -> int: # return new unique elem length
            i, j = 0, 0
            while j < len(nums):
                if nums[i] != nums[j]:
                    nums[i+1] = nums[j]
                    i += 1
                j += 1
            return i + 1
        if len(nums) == 0:
            return 0
        nums.sort()
        n: int = remove_duplicate()
        max_seq: int = 1 # longest sequence
        seq: int = 1 # sequence
        for i in range(1, n):
            if nums[i] - nums[i-1] != 1:
                max_seq = max(max_seq, seq)
                seq = 1
            else:
                seq += 1
        max_seq = max(max_seq, seq)
        return max_seq

T = int(input())
while T:
    arr = [int(x) for x in input()[1:-1].split(",")]
    print(Solution().longestConsecutive(arr))
    T -= 1
