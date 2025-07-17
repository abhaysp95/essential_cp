/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *middleNodeBruteForce(ListNode *head) {
    int size = 0;
    ListNode *ptr = head;
    while (ptr) {
      size++;
      ptr = ptr->next;
    }
    ptr = head;
    for (int i = 0; i < size / 2; i++) {
      ptr = ptr->next;
    }
    return ptr;
  }
};
