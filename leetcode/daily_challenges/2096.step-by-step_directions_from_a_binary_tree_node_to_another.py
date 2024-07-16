#!/usr/bin/env python3

from typing import Deque, List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class NodeNotFoundException(Exception):
    pass

def make_tree_from_level_order_traversal(nodes: List[str]) -> Optional[TreeNode]:
    if len(nodes) == 0 or nodes[0] == 'null':
        return None
    root: Optional[TreeNode] = TreeNode(int(nodes[0]))
    q = Deque() # type alias to collections.deque
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

# NOTE: Start with root node. Check for startValue and see which subtree it comes from. Do the same for destValue.
# If they both come from different side, then you got their common ancestor, and you can now perform the printing path part,
# but if they both come from same side, change the root to this subtree side and also check if this new root is startValue or destValue or none.
# If this new root node is any of the two, then if it is startValue, you'll traverse the tree down to find the destValue.
# Your argument should have direction and when it reaches destvalue it should start returning that direction
# and depending on that if it came from 'L', append 'R', if came from 'R' append 'L'.
# if it is destvalue above, you just move down and get the depth and that many 'U' will do the job

# This is not a good approach, because first I'm traversing the tree to look for the direction of the sv or dv,
# and then I'm again traversing after some time/operation to make the path
# class Solution:
#     def getDirections(self, root: Optional[TreeNode], sv: int, dv: int) -> str:
#         if root == None:
#             return ""
#         return ""
#
#     def determine_dir(self, root: Optional[TreeNode], sv: int, dv: int) -> str:
#         if root == None:
#             return ""
#         if root.val != sv and root.val != dv:
#             sv_at_left, sv_at_right = False, False
#             sv_at_left = self.find_node(root.left, sv)
#             if not sv_at_left:
#                 sv_at_right = self.find_node(root.right, sv)
#             if not sv_at_right:
#                 raise NodeNotFoundException
#             dv_at_left, dv_at_right = False, False
#             dv_at_left = self.find_node(root.left, dv)
#             if not dv_at_left:
#                 dv_at_right = self.find_node(root.right, dv)
#             if not dv_at_right:
#                 raise NodeNotFoundException
#
#             # check the direction
#             # common ancestor is root
#             if (sv_at_left and dv_at_right) or (sv_at_right and dv_at_left):
#                 path = self.get_path(root, sv, dv)
#                 return path
#             # same parent
#             else:
#                 if (sv_at_left and dv_at_left):
#                     return self.determine_dir(root.left, sv, dv)
#                 elif (sv_at_right or dv_at_right):
#                     return self.determine_dir(root.right, sv, dv)
#         else:
#             return self.get_path(root, sv, dv)
#         raise Exception("Should not reach at bottom")
#
#     # check here if root.val is sv or dv or neither
#     def get_path(self, root: Optional[TreeNode], sv: int, dv: int) -> str:
#         if root == None:
#             raise Exception("Root shouldn't be None")
#         if root.val == sv:
#             pass
#             # return path_source_to_dest(root, dv)
#         elif root.val == dv:
#             pass
#             # return path_dest_to_source(root, sv)
#         else:
#             pass
#         return ""
#
#
#
#     def find_node(self, root: Optional[TreeNode], val: int) -> bool:
#         return False


# get lowest commen ancestor
def get_lca(root: TreeNode, p: int, q: int) -> Optional[TreeNode]:
    def recurse(root, p, q):
        if root == None:
            return root
        if root.val == p or root.val == q:
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

def if_node_exists(root, val) -> bool:
    if root == None:
        return False
    if root.val == val:
        return True
    return if_node_exists(root.left, val) or if_node_exists(root.right, val)

def get_depth(root, val):
    if root == None:
        return 0
    if root.val == val:
        return 1
    ld, rd = 0, 0
    ld = get_depth(root.left, val)
    if ld:
        return ld + 1
    rd = get_depth(root.right, val)
    if rd:
        return rd + 1
    return 0
    
def get_traversal_path(root, val, dir):
    if root == None:
        return ''
    if root.val == val:
        return dir
    ret_dir = get_traversal_path(root.left, val, 'L')
    if ret_dir != '':
        return dir + ret_dir
    ret_dir = get_traversal_path(root.right, val, 'R')
    if ret_dir != '':
        return dir + ret_dir
    return ''


# psuedo-code
# if root == p:
#     traverse(p to q path)
# elif root = q:
#     d = detph(q to p) # str = d * 'U'
# else:
#     if (p on root.left): # the q will be on right
#         str = (depth of root to p on the left side) * 'U' + path_from_root_to_q on right side
#     else: # q will be on left side
#         str = (depth of root to p on right side) * 'U' + path from root to q on left side
class Solution:
    def getDirections(self, root: Optional[TreeNode], sv: int, dv: int) -> str:
        if root == None:
            return ""
        if root.val == sv:
            path = get_traversal_path(root.left, dv, 'L')
            if path == '':
                path = get_traversal_path(root.right, dv, 'R')
            return path
        elif root.val == dv:
            return 'U' * (get_depth(root, sv) - 1)
        else:
            print("else")
            lca_node = get_lca(root, sv, dv) # find ancestor node
            if lca_node == None:
                raise Exception("There should be a common ancestor here")
            print(f"lca: {lca_node.val}")
            # if p on left side
            if lca_node.val == sv:
                path = get_traversal_path(lca_node.left, dv, 'L')
                if path == '':
                    path = get_traversal_path(lca_node.right, dv, 'R')
                return path
            if lca_node.val == dv:
                return 'U' * (get_depth(lca_node, sv) - 1)
            if if_node_exists(lca_node.left, sv):
                print(f"{sv} on left")
                return 'U' * (get_depth(lca_node, sv) - 1) + get_traversal_path(lca_node.right, dv, 'R')
            else: # p is on right side
                print(f"{dv} on left")
                return 'U' * (get_depth(lca_node, sv) - 1) + get_traversal_path(lca_node.left, dv, 'L')


def main():
    line = input().split(" ")
    node_list = [x for x in line[0][1:][:-1].split(",")]
    start = int(line[1])
    end = int(line[2])
    root = make_tree_from_level_order_traversal(node_list)
    if root == None:
        raise NodeNotFoundException
    new_node_list = perform_level_order_traversal(root)
    for node in new_node_list:
        print(node, end=" ")
    print()
    solve = Solution()
    print(solve.getDirections(root, start, end))
    # print(f"depth(root, 5): {get_depth(root, 5)}")
    # print(f"depth(root, 1): {get_traversal_path(root.left, 1, 'L')}")
    # print(f"depth(root, 3): {get_traversal_path(root.left, 3, 'L')}")
    # print(f"depth(root, 2): {get_traversal_path(root.right, 2, 'R')}")
    # print(f"depth(root, 6): {get_traversal_path(root.right, 6, 'R')}")
    # print(f"depth(root, 4): {get_traversal_path(root.right, 4, 'R')}")


if __name__ == "__main__":
    main()
