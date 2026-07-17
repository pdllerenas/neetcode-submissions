class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hash1 = {};
        unordered_map<char, int> hash2 = {};
        for (int i = 0; i < s.size(); i++) {
            hash1[s[i]]++;
            hash2[t[i]]++;
        }
        return hash1 == hash2;
    }
};
