import typing as ty

class Solution:
    def groupAnagrams(self, strs: ty.List[str]) -> ty.List[ty.List[str]]:
        d: dict[str, list[str]] = {}
        for x in strs:
            if (sx := "".join(sorted(x))) not in d:
                d[sx] = []
            d[sx].append(x)
        return [x for x in d.values()]

T = int(input())
strs = [x[1:-1] for x in input()[1:-1].split(",")]
print(Solution().groupAnagrams(strs))
