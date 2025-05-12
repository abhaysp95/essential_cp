class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        def get_dict(s: str) -> dict:
            d: dict = {}
            for c in s:
                if c not in d:
                    d[c] = 0
                d[c] += 1
            return d
        d1 = get_dict(s)
        d2 = get_dict(t)
        if d1 != d2:
            return False
        return True

T: int = int(input())
while T:
    s: str = input()
    t: str = input()
    print(Solution().isAnagram(s, t))
    T -= 1
