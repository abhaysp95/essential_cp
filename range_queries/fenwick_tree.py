# Fenwick tree is useful when you have to perform range based operation
# like, get the sum for a range and if there are q updates then this would
# be very useful as this would take O(qlog(n))

# adding 0 at start to make this 1-based index
arr = [0] + list(map(int, input().split(",")))
i = int(input()) # range start
j = int(input()) # range end
q = int(input()) # count for update point operation


# NOTE: actual n = len(arr) - 1

# NOTE: if you don't remember that "bitwise and" two's compliment of the number with itself gives lsb
def get_lsb(num):
    if num == 0:
        return 0 # caller should be careful cause this could lead to infinite loop for caller
    i = 0
    while True:
        if num & (1 << i):
            return 1 << i
        i += 1

# make fenwick tree in O(nlog(n)) time, basically follows the same approach to point update
def make_fenwick_tree_naively(arr):
    tree = [0] * len(arr)

    def make_fenwick_node(i):
        x = i
        while i < len(arr): # from 1 to actual n inclusive
            tree[i] += arr[x]
            i += i & -i # lsb

    for i in range(1, len(arr)):
        make_fenwick_node(i)

    return tree


# effecient approach to make fenwick tree
def make_fenwick_tree(arr):
    tree = [0] * len(arr)

    for i in range(1, len(arr)):
        x = i
        tree[i] += arr[x]
        i += i & -i
        if i < len(arr):
            tree[i] += tree[x] # cascading effect

    return tree

# NOTE: Difference between the two approach is, 1st one as soon as dependent node gets some value
# it sends it to the node it is dependent upon.
# But in the second way, it gets all its own value first and just sends it to the next node it is dependent upon
# which in turn sends to its next node which this node is dependent upon, creating "cascading effect".

def get_sum_for_node(i, tree):
    sum = 0
    while i > 0:  # don't go till 0, because 0 & -0 == 0
        sum += tree[i]
        i -= i & -i

    return sum

def get_range_sum(i, j, tree):
    if i == 0 or j == 0:
        return 0  # or probably raise error
    return get_sum_for_node(j, tree) - get_sum_for_node(i - 1, tree)

# NOTE: this function is basically the same as how we make fenwick tree the naive way
# or you can consider the statement for vice-versa
def make_update_point_change(idx, val, tree):
    while idx < len(tree):
        # NOTE: this could also be a simple assignment operation
        # in that case, increment tree[idx] += val - tree[idx]
        tree[idx] += val
        idx += idx & -idx

tree = make_fenwick_tree(arr)
print(tree)
print("initial range sum:", get_range_sum(i, j, tree))

while q:
    # NOTE: x is index and thus it should be 1-based (confirm this in constraint of question)
    x, val = list(map(int, input().split(" ")))
    print("x, val:", x, val)
    make_update_point_change(x, val, tree)
    print(tree)
    print(get_range_sum(i, j, tree))
    q -= 1
