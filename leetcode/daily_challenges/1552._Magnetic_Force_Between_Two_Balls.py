class Solution(object):
    def maxDistance(self, position: list[int], m: int) -> int:
        position.sort()
        d = 1
        last_placed = []
        while True:
            cur = 1
            placed = [position[0]]
            mind = 1e9
            while cur < len(position) and len(placed) < m:
                diff = position[cur] - placed[-1]
                if diff >= d:
                    mind = min(mind, diff)
                    placed.append(position[cur])
                cur += 1
            d = mind + 1
            if len(placed) < m:
                break
            last_placed = placed

        diff_list = []
        for i in range(1, len(last_placed)):
            diff_list.append(last_placed[i] - last_placed[i - 1])
        return min(diff_list)


str = input()[:-1]
str = str[1:]
position = [int(x) for x in str.split(',')]
m = int(input())

solve = Solution()
print(solve.maxDistance(position, m))
