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
        if 2*l+2 >= len(nodes):
            break
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



def get_lowest_common_ancestor(root, val1, val2):
    if root == None:
        return None
    if root== val1 or root == val2:
        return root
    l = get_lowest_common_ancestor(root.left, val1, val2)
    r = get_lowest_common_ancestor(root.right, val1, val2)
    if l != None and r != None:
        return root
    elif l == None:
        return r
    elif r == None:
        return l
    return None

def get_depth(root, val):
    if root == None:
        return 0
    if root == val:
        return 1
    d = get_depth(root.left, val)
    if d:
        return d + 1
    d = get_depth(root.right, val)
    if d:
        return d + 1
    return 0


# TODO: memoize the depth (check beforehand, and check inside the get_depth also while getting depth)


INF = int(1e9 + 7)

class Solution:
    # the strategy fails because values in nodes are not unique, the thus the value of lca we get is wrong
    def countPairs(self, root: TreeNode, distance: int) -> int:
        leaf_nodes = []
        count = 0

        def get_leaf_nodes(root):
            if root == None:
                return
            print(f"root: {root.val}")
            if root.left == None and root.right == None:
                leaf_nodes.append(root)
            if root.left != None:
                get_leaf_nodes(root.left)
            if root.right != None:
                get_leaf_nodes(root.right)

        get_leaf_nodes(root)
        print(f"len: {len(leaf_nodes)}")

        for i in range(len(leaf_nodes)):
            for j in range(i, len(leaf_nodes)):
                if i == j:
                    continue
                lca_node = get_lowest_common_ancestor(root, leaf_nodes[i], leaf_nodes[j])
                if lca_node == None:
                    raise Exception("Should get lca node")
                depth_x = get_depth(lca_node, leaf_nodes[i]) - 1
                depth_y = get_depth(lca_node, leaf_nodes[j]) - 1
                print(f"x: {leaf_nodes[i].val}, y: {leaf_nodes[j].val}, lca: {lca_node.val}, dx: {depth_x}, dy: {depth_y}")
                if depth_x + depth_y <= distance:
                    count += 1
        return count


def main():
    line = input().split(" ")
    node_list = [x for x in line[0][1:][:-1].split(",")]
    dist_atleast = int(line[1])
    root = make_tree_from_level_order_traversal(node_list)
    print(perform_level_order_traversal(root))
    if root == None:
        raise Exception("Root should be found")
    solve = Solution()
    print(solve.countPairs(root, dist_atleast))

if __name__ == "__main__":
    main()

# input: [1,2,3,4,5,6,7] 3
# input: [7,1,4,6,null,5,3,null,null,null,null,null,2] 3
