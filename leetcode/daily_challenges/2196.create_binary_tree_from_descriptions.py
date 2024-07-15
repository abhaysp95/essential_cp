#!/usr/bin/env python3

from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

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

class Solution:
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

def main():
    given = input()[1:][:-1].split("],")
    desc: List[List[int]] = []
    for i, single in enumerate(given):
        if i == len(given) - 1:
            desc.append([int(x) for x in single[1:][:-1].split(",")])
        else:
            desc.append([int(x) for x in single[1:].split(",")])
    solve = Solution()
    root: Optional[TreeNode] = solve.createBinaryTree(desc)

    print("Final tree:")
    print_tree(root)
    print("----------")

if __name__ == "__main__":
    main()
