// Brute force — O(n²) time, O(1) space
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {         // fix position i
            bool unique = true;

            for (int j = 0; j < n; j++) {     // scan whole string
                if (i != j && s[i] == s[j]) {
                    unique = false;           // found a duplicate
                    break;
                }
            }

            if (unique) return i;             // first unique found
        }

        return -1;  // no unique char
    }
};