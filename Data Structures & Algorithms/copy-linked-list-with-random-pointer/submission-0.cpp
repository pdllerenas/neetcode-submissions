/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> mp;
    Node *cur = head;
    while (cur) {
        mp[cur] = new Node(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        mp[cur]->next = (cur->next) ? mp[cur->next] : nullptr;
        mp[cur]->random = (cur->random) ? mp[cur->random] : nullptr;
        cur = cur->next;
    }
    return mp[head];
  }
};
