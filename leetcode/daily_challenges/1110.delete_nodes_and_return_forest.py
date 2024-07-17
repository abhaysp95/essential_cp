#!/usr/bin/env python3

from collections import deque
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def make_tree_from_level_order_traversal(nodes: List[str]) -> Optional[TreeNode]:
    if len(nodes) == 0 or nodes[0] == 'null':
        return None
    root = TreeNode(int(nodes[0]))
    q = deque()
    q.append((root, 0))

    while len(q):
        p, l = q.popleft()
        if 2*l+1 >= len(nodes):
            break
        if nodes[2*l+1] != 'null':
            p.left = TreeNode(int(nodes[2*l+1]))
            q.append((p.left, 2*l+1))
        if nodes[2*l+2] != 'null':
            p.right = TreeNode(int(nodes[2*l+2]))
            q.append((p.right, 2*l+2))
    return root

def perform_level_order_traversal(root: Optional[TreeNode]) -> List[str]:
    if root == None:
        return []
    nodes = [str(root.val)]
    q = deque()
    q.append(root)

    while len(q):
        p = q.popleft()
        if p.left != None:
            q.append(p.left)
        nodes.append('null' if p.left == None else str(p.left.val))
        if p.right != None:
            q.append(p.right)
        nodes.append('null' if p.right == None else str(p.right.val))

    idx = len(nodes) - 1
    while idx >= 0:
        if nodes[idx] != 'null':
            break
        idx -= 1
    return nodes[:idx + 1]


class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        if root == None:
            return []
        ind_nodes = [root]

        def perform_deletion(root, parent, is_left_child, to_del):
            if root == None:
                return []
            if root.val == to_del:
                if parent != None:
                    if is_left_child:
                        parent.left = None
                    else:
                        parent.right = None
                nodes = []
                if root.left:
                    nodes.append(root.left)
                if root.right:
                    nodes.append(root.right)
                return nodes
            nodes = perform_deletion(root.left, root, True, to_del)
            if len(nodes):
                return nodes
            nodes = perform_deletion(root.right, root, False, to_del)
            if len(nodes):
                return nodes
            return []

        for delval in to_delete:
            for idx, node in enumerate(ind_nodes):
                new_nodes = perform_deletion(node, None, True, delval)
                if node.val == delval:
                    ind_nodes = ind_nodes[:idx] + ind_nodes[idx + 1:]
                if len(new_nodes):
                    for node in new_nodes:
                        ind_nodes.append(node)
                    break

        return ind_nodes

def main():
    line = input().split(" ")
    nodes = [x for x in line[0][1:][:-1].split(",")]
    to_delete = [int(x) for x in line[1][1:][:-1].split(",")]
    root = make_tree_from_level_order_traversal(nodes)
    print(perform_level_order_traversal(root))
    solve = Solution()
    ind_nodes = solve.delNodes(root, to_delete)
    forest = []
    for node in ind_nodes:
        forest.append(perform_level_order_traversal(node))
    print(forest)

if __name__ == "__main__":
    main()
