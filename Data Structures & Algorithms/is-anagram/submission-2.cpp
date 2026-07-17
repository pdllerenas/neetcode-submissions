class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> s_cnt, t_cnt;
        for (int i = 0; i < s.size(); i++) {
            if (s_cnt[s[i]]) {
               s_cnt[s[i]]++;
            } 
            else {
                s_cnt[s[i]] = 1;
            }
            if (t_cnt[t[i]]) {
                t_cnt[t[i]]++;
            } else {
                t_cnt[t[i]] = 1;
            }
        }
        return t_cnt == s_cnt;
    }
};
