#!/usr/bin/env python3

from abc import ABCMeta, abstractmethod
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(metaclass = ABCMeta):
    @abstractmethod
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return NotImplementedError

# the solution creates a new resultant list
class SolutionCreatingNewList(Solution):
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

# the solution makes changes in existing list
class SolutionWithExistingList(Solution):
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head

        prev, cur = head, head.next
        sum = 0
        while cur != None:
            if cur.val == 0:
                prev.val = sum
                if cur.next != None:
                    prev.next = cur
                    prev = prev.next
                else:
                    prev.next = None
                sum = 0
            else:
                sum += cur.val
            cur = cur.next
        return head


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
    print("Formed list: ", end="")
    print_ll(head)
    solve = SolutionWithExistingList()
    res_head = solve.mergeNodes(head)
    print("Resultant list: ", end="")
    print_ll(res_head)
    

if __name__ == "__main__":
    main()
