// Brute force — O(n²) time, O(min(n,m)) space
// m = size of character set (26 for lowercase, 128 for ASCII)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), best = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;         // chars in current window

            for (int j = i; j < n; j++) {
                if (seen.count(s[j])) break; // duplicate → stop extending
                seen.insert(s[j]);
                best = max(best, j - i + 1); // update best length
            }
        }
        return best;
    }
};