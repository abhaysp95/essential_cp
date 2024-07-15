#!/usr/bin/env python3

from abc import ABCMeta, abstractmethod
from typing import Deque, Dict, List, Optional, Set

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(metaclass = ABCMeta):
    @abstractmethod
    def createBinaryTree(self, description: List[List[int]]) -> Optional[TreeNode]:
        pass


class RootNotFoundError(Exception):
    pass

def traverse(root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    if root == None:
        return root
    print(f"got {root.val}")
    if root.val == val:
        print(f"matched: {root.val}")
        return root
    left = traverse(root.left, val)
    if left != None:
        return left
    right = traverse(root.right, val)
    if right != None:
        return right
    return None

# traverse
def print_tree(root: Optional[TreeNode]):
    if root == None:
        return
    print(f" {root.val} ", end="")
    if root.left != None:
        print_tree(root.left)
    else:
        print(" null ", end="")
    if root.right != None:
        print_tree(root.right)
    else:
        print(" null ", end="")

# Getting "Time Limit Exceeded"
class SequentialTreeFormingSolution(Solution):
    def createBinaryTree(self, description: List[List[int]]) -> Optional[TreeNode]:
        root: Optional[TreeNode] = None
        parents: List[TreeNode] = []
        for single in description:
            parent, child = None, None
            pidx, cidx = -1, -1
            for i, root in enumerate(parents):
                parent = traverse(root, single[0])
                if parent != None:
                    pidx = i
                    break
            for i, root in enumerate(parents):
                child = traverse(root, single[1])
                if child != None:
                    cidx = i
                    break
            if parent != None and child != None:
                if single[2]:
                    parent.left = child
                else:
                    parent.right = child
                parents = parents[:cidx] + parents[cidx + 1:]
            elif parent == None and child == None:
                root = TreeNode(single[0])
                child = TreeNode(single[1])
                if single[2]:
                    root.left = child
                else:
                    root.right = child
                parents.append(root)
            elif parent == None:
                parent = TreeNode(single[0])
                if root == None:
                    raise RootNotFoundError
                if single[2]:
                    parent.left = child
                else:
                    parent.right = child
                root = parent
                parents[cidx] = root
            else:
                child = TreeNode(single[1])
                if root == None:
                    raise RootNotFoundError
                if single[2]:
                    parent.left = child
                else:
                    parent.right = child
        return parents[0]

class FindingParentSolution(Solution):
    def createBinaryTree(self, description: List[List[int]]) -> Optional[TreeNode]:
        q = Deque()
        d: Dict[int, List[Optional[int]]] = dict()
        for info in description:
            if info[0] not in d:
                d[info[0]] = [None, None]
            if info[2] == 0:
                d[info[0]][1] = info[1] # right
            else:
                d[info[0]][0] = info[1] # left

        # find the root node first
        root: Optional[TreeNode] = None
        for key in d.keys():
            found = False
            for values in d.values():
                print(f"looking {key} in {values}")
                if key in values:
                    found = True
            if not found:
                root = TreeNode(key)

        if root == None:
            raise RootNotFoundError
        print(f"root: {root.val}")

        for i, value in enumerate(d[root.val]):
            if i == 0 and value != None:
                root.left = TreeNode(value)
                q.append(root.left)
            elif i == 1 and value != None:
                root.right = TreeNode(value)
                q.append(root.right)

        # debug
        for ele in q:
            print(f"parent: {ele.val}")


        while len(q) != 0:
            parent = q.pop()
            print(f"making for parent: {parent.val}")
            if parent.val not in d:
                continue
            values = d[parent.val]
            for i, value in enumerate(values):
                if i == 0 and value != None:
                    parent.left = TreeNode(value)
                    q.append(parent.left)
                elif i == 1 and value != None:
                    parent.right = TreeNode(value)
                    q.append(parent.right)

        return root

def main():
    given = input()[1:][:-1].split("],")
    desc: List[List[int]] = []
    for i, single in enumerate(given):
        if i == len(given) - 1:
            desc.append([int(x) for x in single[1:][:-1].split(",")])
        else:
            desc.append([int(x) for x in single[1:].split(",")])
    solve = FindingParentSolution()
    root: Optional[TreeNode] = solve.createBinaryTree(desc)

    print("Final tree:")
    print_tree(root)
    print("\n----------")

if __name__ == "__main__":
    main()
