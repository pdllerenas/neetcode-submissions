/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode *curr = head, *curr2 = head;
    while (curr && curr2) {
      curr = curr->next;
      if (curr2->next == nullptr) {
        return false;
      }
      curr2 = curr2->next->next;
      if (curr == curr2) {
        return true;
      }
    }
    return false;
  }
};
