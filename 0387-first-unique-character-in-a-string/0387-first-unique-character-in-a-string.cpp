// Brute force — O(n²) time, O(1) space
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int n = s.size();

//         for (int i = 0; i < n; i++) {         // fix position i
//             bool unique = true;

//             for (int j = 0; j < n; j++) {     // scan whole string
//                 if (i != j && s[i] == s[j]) {
//                     unique = false;           // found a duplicate
//                     break;
//                 }
//             }

//             if (unique) return i;             // first unique found
//         }

//         return -1;  // no unique char
//     }
// };




// Optimal — O(n) time, O(1) space (26 is constant)
class Solution {
public:
    int firstUniqChar(string s) {

        // Pass 1: count frequencies — O(n)
        int freq[26] = {};              // {} zero-initialises all 26 slots
        for (char c : s)
            freq[c - 'a']++;           // 'a'→0 ... 'z'→25

        // Pass 2: find first with freq == 1 — O(n)
        for (int i = 0; i < s.size(); i++)
            if (freq[s[i] - 'a'] == 1)
                return i;               // first unique — return index

        return -1;                      // no unique char found
    }
};