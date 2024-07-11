from typing import List

class Solution:
    def minOperations(self, logs: List[str]) -> int:
        total_op = 0
        for op in logs:
            if op == "./":
                pass
            elif op == "../":
                total_op = total_op - 1 if total_op > 0 else 0
            else:
                total_op += 1
        return total_op

def main():
    ops = [x[1:][:-1] for x in input()[1:][:-1].split(",")]
    solve = Solution()
    print(solve.minOperations(ops))

if __name__ == "__main__":
    main()
