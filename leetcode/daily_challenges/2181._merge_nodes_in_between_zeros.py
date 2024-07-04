#!/usr/bin/env python3

from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head

        cur = head.next
        new_list = ListNode()
        new_head = new_list

        sum = 0
        while cur != None:
            if cur.val == 0:
                new_list.next = ListNode()
                new_list = new_list.next
                new_list.val = sum
                sum = 0
            else:
                sum += cur.val
            cur = cur.next

        return new_head.next

def make_ll(arr: List[int]) -> Optional[ListNode]:
    head = ListNode()
    cur = head
    for num in arr:
        cur.next = ListNode()
        cur = cur.next
        cur.val = num
        cur.next = None
    return head.next


def print_ll(head: Optional[ListNode]):
    print("Printing List:")
    if head == None:
        return
    cur = head

    while cur != None:
        if cur != head:
            print(" -> ", end="", sep="")
        print(cur.val, end="", sep="")
        cur = cur.next
    print()

def main():
    lst = [int(x) for x in input()[1:][:-1].split(",")]
    head = make_ll(lst)
    print("Formed list:", end="")
    print_ll(head)
    solve = Solution()
    res_head = solve.mergeNodes(head)
    print("Resultant list:", end="")
    print_ll(res_head)
    

if __name__ == "__main__":
    main()
