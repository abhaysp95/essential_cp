from typing import List


# Intution: we have two prefix-sum arrays
# psum1 = prefix sum irrespective of grumpiness
# psum2 = prefix sum when owner is not grumpy
# At any minute i, we can get the max. satisfied customer by
# adding from psum1 before the ith minute and after the (i + minute)th minute
# and adding the range of i to (i + minute)th minute
# for each index we can update the maximum which will be answer
class SolutionPrefixSum:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        psum1 = [0] * (len(customers) + 1)
        psum2 = psum1.copy()
        for i in range(len(customers)):
            psum1[i + 1] = psum1[i]
            psum1[i + 1] += customers[i]
        for i in range(len(customers)):
            psum2[i + 1] = psum2[i]
            if grumpy[i] == 0:
                psum2[i + 1] += customers[i]
        print(f"psum1: {psum1}")
        print(f"psum2: {psum2}")

        res = 0
        i = 0
        while i + minutes < len(customers) + 1:
            sum = psum2[i] + (psum1[i + minutes] - psum1[i]) + psum2[-1] - psum2[i + minutes];
            res = max(res, sum)
            i += 1

        return res

# Intution: get the window where customers are max satisfied.
# Window will be of size minutes and max satisfied customer in that window should be the grumped customer,
# because that will tell us that this much customer we will gain
# if we use the secret technique in this window and base customer.
# In the chosen window, non-grumped customers are added to base-satisfied customers,
# that way they can pulled in both the cases when they are in the window or outside the window
class SolutionSlidingWindow:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        l = 0  # left
        w, mw = 0, 0  # window, max_window
        bs = 0  # base_satisfied
        for r in range(len(customers)):
            print(f"cust: {customers[r]}, grumpy: {grumpy[r]}")
            if grumpy[r]:
                w += customers[r]
            else:
                bs += customers[r]
            print(f"[before] w: {w}, bs: {bs}")

            if r - l + 1 > minutes:
                if grumpy[l]:
                    w -= customers[l]
                l += 1
                print(f"[after] w: {w}, bs: {bs}")
            mw = max(mw, w)
            print(f"l: {l}, r: {r}, mw: {mw}")

        return bs + mw


# TODO: giving wrong result
class SolutionRecursion:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:

        def find_satisfied(idx: int, grump_exhausted: bool):
            if idx >= len(customers):
                return 0
            left, right = 0, 0
            # we have choice to use minutes, when he is grumpy 
            if grumpy[idx] == 1:
                if not grump_exhausted:
                    msf = 0
                    for m in range(minutes):
                        if idx + m == len(customers):
                            break
                        msf += customers[idx + m]
                    left = msf + find_satisfied(idx + minutes, True)
                left = max(left, find_satisfied(idx + 1, False))
            else:
                right = customers[idx] + find_satisfied(idx + 1, False)
            return max(left, right)

        return find_satisfied(0, False)

def main():
    # input customers
    line = input()
    line = line[1:][:-1]
    customers = [int(x) for x in line.split(',')]
    # input grumpy
    line = input()
    line = line[1:][:-1]
    grumpy = [int(x) for x in line.split(',')]
    minutes = int(input())

    solve = SolutionPrefixSum().maxSatisfied(customers, grumpy, minutes)
    print(solve)

if __name__ == "__main__":
    main()
