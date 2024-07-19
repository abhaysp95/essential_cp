#!/usr/bin/env python3

from typing import List

INF = int(1e9)

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        ans = []
        for row in matrix:
            smi = 0
            for i, c in enumerate(row):
                if c < row[smi]:
                    smi = i
            # check if it is min in column
            biggest = True
            for r in range(len(matrix)):
                if matrix[r][smi] > row[smi]:
                    biggest = False
                    break
            if biggest:
                ans.append(row[smi])
        return ans
        
def main():
    line = input()[1:][:-1].split("],")
    mat = []
    for i, row in enumerate(line):
        if i == len(line) - 1:
            mat.append([int(x) for x in row[1:][:-1].split(",")])
        else:
            mat.append([int(x) for x in row[1:].split(",")])
    solve = Solution()
    ans = solve.luckyNumbers(mat)
    print(ans)


if __name__ == "__main__":
    main()
