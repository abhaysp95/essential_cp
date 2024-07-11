#!/usr/bin/env python3

from typing import List

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        sum = 0
        chef_idx = 0
        for data in customers:
            arrival, time = data
            if chef_idx == 0:
                chef_idx = arrival
            elif arrival <= chef_idx:
                pass
            elif chef_idx < arrival:
                chef_idx = arrival
            chef_idx += time
            sum += (chef_idx - arrival) # waiting time for customer
        return sum / len(customers)

def main():
    line = input()[1:][:-1]
    data: List[List[int]] = []
    blocks = line.split("],")
    for idx, block in enumerate(blocks):
        if idx == len(blocks) - 1:
            data.append([int(x) for x in block[1:][:-1].split(",")])
        else:
            data.append([int(x) for x in block[1:].split(",")])

    solve = Solution()
    print("%0.5f" % solve.averageWaitingTime(data))

if __name__ == "__main__":
    main()
