#!/usr/bin/env python3

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        fn, sn, prev, cur = None, None, None, head
        fd, sd, mind, maxd, cidx = -1, -1, -1, -1, 0

        while cur != None:
            if prev != None and cur.next != None:  # we found critical node
                # print(f"prev: {prev.val}, next: {cur.next.val}, cur: {cur.val}")
                if (prev.val > cur.val and cur.next.val > cur.val) or (prev.val < cur.val and cur.next.val < cur.val):
                    if fn == None:
                        fn = cur
                        fd = cidx
                    elif sn == None:
                        sn = cur
                        sd = cidx
                        mind = sd - fd
                    else:
                        new_mind = cidx - sd
                        mind = mind if mind < new_mind else new_mind
                        sd = cidx
                        maxd = cidx - fd
            prev = cur
            cur = cur.next
            cidx += 1

        maxd = maxd if maxd != -1 else mind
        return [mind, maxd]

def make_ll(arr: List[int]) -> Optional[ListNode]:
    if len(arr) == 0:
        return None
    head = ListNode()
    cur = head
    for x in arr:
        cur.next = ListNode()
        cur = cur.next
        cur.val = x
    return head.next

def print_ll(head: Optional[ListNode]):
    if head == None:
        return
    cur = head
    while cur != None:
        if cur != head:
            print(" -> ", end="")
        print(cur.val, end="")
        cur = cur.next

def main():
    arr = [int(x) for x in input()[1:][:-1].split(",")]
    head = make_ll(arr)
    print_ll(head)
    print()
    solve = Solution()
    print(solve.nodesBetweenCriticalPoints(head))

if __name__ == "__main__":
    main()
