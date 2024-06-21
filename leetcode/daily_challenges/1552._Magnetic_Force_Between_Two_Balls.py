# Following question is based on: https://www.spoj.com/problems/AGGRCOW/ 

class Solution(object):
    def maxDistance(self, position: list[int], m: int) -> int:
        """
        :type n: int
        :type quantities: List[int]
        :rtype: int
        """
        position.sort() 

        low = 1
        high = position[-1] - position[0]
        ans = 1
        while low <= high:
            mid = low + ((high - low) // 2)
            placed = self.canPlace(position, m, mid)
            if placed:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans
    
    def canPlace(self, position: list[int], m: int, d: int) -> bool:
        placed = 1
        lastPlaced = position[0]
        for i in range(1, len(position)):
            if position[i] - lastPlaced >= d:
                lastPlaced = position[i]
                placed += 1
            if placed >= m:
                return True
        return False

# brute force solution
class SolutionBruteForce(object):
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


def main() -> None:
    str = input()[:-1]
    str = str[1:]
    position = [int(x) for x in str.split(',')]
    m = int(input())

    solve = SolutionBruteForce()
    print(solve.maxDistance(position, m))

if __name__ == "__main__":
    main()
