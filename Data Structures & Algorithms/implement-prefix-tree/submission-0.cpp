class TrieNode {
public:
    bool eow;
    unordered_map<int, TrieNode*> children;
    TrieNode() : eow(false) {}
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.contains(c)) {
                cur->children[c] = new TrieNode{};
            }
            cur = cur->children[c];
        }
        cur->eow = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.contains(c)) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->eow == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children.contains(c)) {
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
