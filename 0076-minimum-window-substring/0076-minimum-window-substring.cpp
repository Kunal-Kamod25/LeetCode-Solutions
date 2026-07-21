class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;

        int count = t.size();     // characters still needed

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            // Include current character
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            // Window is valid
            while (count == 0) {

                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove left character
                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};