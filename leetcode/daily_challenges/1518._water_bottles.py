#!/usr/bin/env python3

class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        sum, spare = 0, 0
        emptied = 0
        while True:
            sum += numBottles
            emptied = numBottles  # bottles are emptied
            if emptied + spare < numExchange: 
                # can't exchange anymore so breakout
                break;
            numBottles = (emptied + spare) // numExchange  # new filled bottles
            spare = (emptied + spare) % numExchange
        return sum

def main():
    line = input().split(" ")
    solve = Solution()
    print(solve.numWaterBottles(int(line[0]), int(line[1])))

if __name__ == "__main__":
    main()
