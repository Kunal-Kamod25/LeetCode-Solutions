class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(string s : strs) {
            string sortS = s;
            sort(sortS.begin(), sortS.end());
            um[sortS].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto& e : um)
            ans.push_back(e.second);

        return ans;
    }
};