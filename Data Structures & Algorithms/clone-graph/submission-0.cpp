/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return {};
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> mp;
        while (!q.empty()) {
            Node* cur = q.front();
            if (!mp[cur]) {
                mp[cur] = new Node{cur->val};
            }
            q.pop();
            for (Node* v : cur->neighbors) {
                if (!mp[v]) {
                    Node* neighbor = new Node{v->val};
                    mp[v] = neighbor;
                    q.push(v);
                }
                mp[cur]->neighbors.push_back(mp[v]);
            }
        }
        return mp[node];
    }
};
