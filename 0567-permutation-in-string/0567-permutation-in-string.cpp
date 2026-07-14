// Match-count variant — O(n) time, O(1) space
// Avoids O(26) array comparison every step
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        if (k > n) return false;

        int pFreq[26] = {}, wFreq[26] = {};
        int matches = 0;  // how many chars have matching freq

        // Build initial frequencies
        for (int i = 0; i < k; i++) {
            pFreq[s1[i] - 'a']++;
            wFreq[s2[i] - 'a']++;
        }
        // Count initial matches
        for (int i = 0; i < 26; i++)
            if (pFreq[i] == wFreq[i]) matches++;

        if (matches == 26) return true;

        for (int R = k; R < n; R++) {
            int addIdx = s2[R]     - 'a';  // incoming char index
            int remIdx = s2[R - k] - 'a';  // outgoing char index

            // Update for incoming char
            if (wFreq[addIdx] == pFreq[addIdx]) matches--;    // was match, will break
            wFreq[addIdx]++;
            if (wFreq[addIdx] == pFreq[addIdx]) matches++;    // now matches again?

            // Update for outgoing char
            if (wFreq[remIdx] == pFreq[remIdx]) matches--;    // was match, will break
            wFreq[remIdx]--;
            if (wFreq[remIdx] == pFreq[remIdx]) matches++;    // now matches again?

            if (matches == 26) return true;
        }
        return false;
    }
};