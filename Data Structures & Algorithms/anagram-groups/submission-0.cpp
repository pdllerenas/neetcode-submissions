class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res = {};
        vector<unordered_map<char, int>> prevMap = {};
        for (int i = 0; i < strs.size(); i++){
            unordered_map<char, int> pMap = {};
            for (int j = 0; j < strs[i].size(); j++){
                if (pMap.count(strs[i][j])){
                    pMap[strs[i][j]]++;
                }
                else {
                    pMap[strs[i][j]] = 1;
                }
            }
            bool found = false;
            for (int k = 0; k < prevMap.size(); k++){
                if (prevMap[k] == pMap) {
                    res[k].push_back(strs[i]);
                    found = true;
                    break;
                } 
            }
            if (!found) {
                prevMap.push_back(pMap);
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};
