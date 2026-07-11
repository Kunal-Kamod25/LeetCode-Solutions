class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return string("aeiou") . find(c) != string :: npos;
        };
        int win = 0 , best = 0;
        for(int i = 0; i < k; i ++) 
            win += isVowel(s[i]);
        best = win;
        for(int i = k; i < s.size(); i ++) {
            win += isVowel(s[i]) - isVowel(s[i-k]); // Slide
            best = max(best , win);
        }
        return best;
    }
};