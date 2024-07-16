#!/usr/bin/env python3

from typing import Deque, List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class NodeNotFoundException(Exception):
    pass

def make_tree_from_level_order_traversal(nodes: List[str], start: int, end: int) -> List[Optional[TreeNode]]:
    if len(nodes) == 0 or nodes[0] == 'null':
        return [None]
    root: Optional[TreeNode] = TreeNode(int(nodes[0]))
    q = Deque() # type alias to collections.deque
    q.append((root, 0))
    start_node, end_node = None, None

    while len(q):
        p, l = q.popleft()
        if p.val == start:
            start_node = p
        if p.val == end:
            end_node = p
        if 2*l+1 >= len(nodes):
            break
        if nodes[2*l+1] != 'null':
            p.left = TreeNode(int(nodes[2*l+1]))
            q.append((p.left, 2*l+1))
        if nodes[2*l+2] != 'null':
            p.right = TreeNode(int(nodes[2*l+2]))
            q.append((p.right, 2*l+2))

    # this is only needed because I need start and end as node
    while len(q):
        p, l = q.popleft()
        if p.val == start:
            start_node = p
        if p.val == end:
            end_node = p

    return [root, start_node, end_node]

def perform_level_order_traversal(root: Optional[TreeNode]) -> List[str]:
    if root == None:
        return ['null']
    node_list: List[str] = []
    q = Deque()
    q.append(root)
    node_list.append(str(root.val))

    while len(q):
        p = q.popleft()
        # don't want to include the child's for leaf node which would be 'null' only
        # if p.left == None and p.right == None:
        #     continue
        node_list.append('null' if p.left == None else str(p.left.val))
        if p.left != None:
            q.append(p.left)
        node_list.append('null' if p.right == None else str(p.right.val))
        if p.right != None:
            q.append(p.right)

    # remove all the 'null's at last
    i = len(node_list) - 1
    while i >= 0:
        if node_list[i] != 'null':
            break
        i -= 1
    return node_list[:i + 1]

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
        def recurse(root, p, q):
            if root == None:
                return root
            if root == p or root == q:
                return root
            l = recurse(root.left, p, q)
            r = recurse(root.right, p, q)
            if l != None and r != None: # p & q exist in different subtrees of node
                return root
            elif l == None: # both are in the right subtree (it is guaranteed by the problem that p & q exist)
                return r
            else: # both are in left subtree
                return l
        return recurse(root, p, q)

def main():
    line = input().split(" ")
    node_list = [x for x in line[0][1:][:-1].split(",")]
    p = int(line[1])
    q = int(line[2])

    print(node_list)
    root = make_tree_from_level_order_traversal(node_list, p, q)
    if root == None:
        raise NodeNotFoundException

    ## debug
    # new_node_list = perform_level_order_traversal(root[0])
    # for node in new_node_list:
    #     print(node, end=" ")
    # print("\n-------------")
    # new_node_list = perform_level_order_traversal(root[1])
    # for node in new_node_list:
    #     print(node, end=" ")
    # print("\n-------------")
    # new_node_list = perform_level_order_traversal(root[2])
    # for node in new_node_list:
    #     print(node, end=" ")
    # print("\n-------------")
    # get out of optional
    if root[0] == None or root[1] == None or root[2] == None:
        return
    sol = Solution()
    res = sol.lowestCommonAncestor(root[0], root[1], root[2])
    print(res.val if res != None else 'null')

if __name__ == "__main__":
    main()
