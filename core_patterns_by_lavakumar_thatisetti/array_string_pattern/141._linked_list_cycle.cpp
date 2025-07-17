struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycleBruteForce(ListNode *head) {
    unordered_set<ListNode *> uset{};
    ListNode *ptr = head;
    while (ptr) {
      if (uset.find(ptr) != uset.end()) return true;
      uset.insert(ptr);
      ptr = ptr->next;
    }
    return false;
  }

  bool hasCycle(ListNode *head) {
    // f is first, s is second and not slow and fast
    ListNode *f = head, *s = head;
    while (s && s->next) {
      f = f->next;
      s = s->next->next;
      if (f == s) return true;
    }
    return false;
  }

  // first approach
  bool _hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    // f is first, s is second and not slow and fast
    ListNode *f = head, *s = head->next;
    while (f != s) {
      if (!s || !s->next) return false;
      f = f->next;
      s = s->next->next;
    }
    return true;
  }
};
