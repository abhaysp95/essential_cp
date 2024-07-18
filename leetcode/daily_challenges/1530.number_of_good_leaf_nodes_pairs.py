#!/usr/bin/env python3

import cProfile
from collections import deque
from typing import List, Optional, Union

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class TRwithParent:
    def __init__(self, val=0, parent=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

def convert_tree_to_with_parent(root, new_root):
    if root == None:
        return None
    if root.left != None:
        new_root.left = TRwithParent(root.left.val)
        new_root.left.parent = new_root
        convert_tree_to_with_parent(root.left, new_root.left)
    if root.right != None:
        new_root.right = TRwithParent(root.right.val)
        new_root.right.parent = new_root
        convert_tree_to_with_parent(root.right, new_root.right)
    return new_root

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

def perform_level_order_traversal_with_parent(root: Optional[TRwithParent]) -> List[List[str]]:
    if root == None:
        return []
    nodes = [[str(root.val), 'null']]
    q = deque()
    q.append(root)

    while len(q):
        p = q.popleft()
        if p.left != None:
            q.append(p.left)
        nodes.append(['null', 'null'] if p.left == None else [str(p.left.val), 'null' if p.left.parent == None else str(p.left.parent.val)])
        if p.right != None:
            q.append(p.right)
        nodes.append(['null', 'null'] if p.right == None else [str(p.right.val), 'null' if p.right.parent == None else str(p.right.parent.val)])

    idx = len(nodes) - 1
    while idx >= 0:
        if nodes[idx][0] != 'null':
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

depth_dict = {} # to memoize finding depth of node
adj_dict = {} # to memoize the check whether a node exists in a tree/sub-tree

def get_depth(root, val):
    if root == None:
        return 0
    if root == val:
        return 1
    if (root, val) in depth_dict:
        return depth_dict[(root, val)]
    d = get_depth(root.left, val)
    if d:
        return d + 1
    d = get_depth(root.right, val)
    if d:
        return d + 1
    return 0

def get_parents(node):
    if node == None:
        return [];
    plist = []
    dist = 1
    while node != None:
        if node.parent != None:
            plist.append([node.parent, dist])
        node = node.parent
        dist += 1
    return plist

def node_exists(root, node) -> bool:
    if root == None:
        return False
    if root == node:
        return True
    if root in adj_dict:
        if node in adj_dict[root]:
            return True
    return node_exists(root.left, node) or node_exists(root.right, node)

class Solution:
    # the strategy fails because values in nodes are not unique, the thus the value of lca we get is wrong
    def countPairs(self, root: Union[TreeNode, TRwithParent], distance: int) -> int:
        leaf_nodes = []
        count = 0

        def get_leaf_nodes(root):
            if root == None:
                return
            if root.left == None and root.right == None:
                leaf_nodes.append(root)
            if root.left != None:
                get_leaf_nodes(root.left)
            if root.right != None:
                get_leaf_nodes(root.right)

        get_leaf_nodes(root)

        for i in range(len(leaf_nodes)):
            parent_list = get_parents(leaf_nodes[i])
            for pinfo in parent_list:
                print(pinfo[0].val, pinfo[1])
            for j in range(i, len(leaf_nodes)):
                if i == j:
                    continue
                for pinfo in parent_list:
                    found = False
                    if node_exists(pinfo[0], leaf_nodes[j]):
                        if pinfo[0] not in adj_dict:
                            adj_dict[pinfo[0]] = [leaf_nodes[i]]
                        if leaf_nodes[j] not in adj_dict[pinfo[0]]:
                            adj_dict[pinfo[0]].append(leaf_nodes[j])
                        found = True
                        # depth_x = get_depth(pinfo[0], leaf_nodes[i])
                        # if depth_x != pinfo[1]:
                        #     print(f"parent: {pinfo[0].val}, leaf[i]: {leaf_nodes[i].val}, pinfo[1]: {pinfo[1]}, depth_x: {depth_x}")
                        depth_x = pinfo[1]
                        if (pinfo[0], leaf_nodes[i]) not in depth_dict:
                            depth_dict[(pinfo[0], leaf_nodes[i])] = depth_x
# TODO: Further optimization could be to get the depth from leaf_nodes[i] to parent, when we are using get_parents(i)
# and to do the same for leaf_nodes[j] when we are operating on node_exists() method
# NOTE: Checked a little bit. First part seems alright, but for second part getting some unexpected things
                        # depth_x -= 1 # don't include self
                        depth_y = get_depth(pinfo[0], leaf_nodes[j])
                        if (pinfo[0], leaf_nodes[j]) not in depth_dict:
                            depth_dict[(pinfo[0], leaf_nodes[j])] = depth_y
                        depth_y -= 1 # don't include self
                        if depth_x + depth_y <= distance:
                            count += 1
                    if found:
                        break

        return count


def main():
    line = input().split(" ")
    node_list = [x for x in line[0][1:][:-1].split(",")]
    dist_atleast = int(line[1])
    root = make_tree_from_level_order_traversal(node_list)
    # print(perform_level_order_traversal(root))
    if root == None:
        raise Exception("Root should be found")
    new_root = TRwithParent(root.val)
    convert_tree_to_with_parent(root, new_root)
    # new_node_list = perform_level_order_traversal_with_parent(new_root)
    # print("\n", new_node_list, sep = " ")
    # print(f"{len(node_list)}, {len(new_node_list)}")

    # if new_root == None:
    #     raise Exception("Root should be found")
    # if new_root.left == None:
    #     raise Exception("Root should be found")
    # if new_root.right == None:
    #     raise Exception("Root should be found")
    # if new_root.left.right == None:
    #     raise Exception("Root should be found")
    # print(new_root.val)
    # print(new_root.left.parent.val)
    # print(new_root.right.parent.val)
    # print(new_root.left.right.val)

    solve = Solution()
    print(solve.countPairs(new_root, dist_atleast))

if __name__ == "__main__":
    cProfile.run('main()')
    # main()

# input: [1,2,3,4,5,6,7] 3
# input: [7,1,4,6,null,5,3,null,null,null,null,null,2] 3
