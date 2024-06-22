from typing import List


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

    solve = SolutionSlidingWindow().maxSatisfied(customers, grumpy, minutes)
    print(solve)

if __name__ == "__main__":
    main()
