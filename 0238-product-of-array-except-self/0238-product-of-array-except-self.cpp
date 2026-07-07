// // Brute force — O(n²) time, O(1) extra space (output not counted)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> answer(n);        // output array (doesn't count as space)

//         for (int i = 0; i < n; i++) {     // fix position i
//             int product = 1;
//             for (int j = 0; j < n; j++) { // multiply all except i
//                 if (j != i) product *= nums[j];
//             }
//             answer[i] = product;
//         }
//         return answer;
//     }
// };







// // Prefix + Suffix — O(n) time, O(n) extra space
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n), suffix(n), answer(n);

//         // Build prefix: prefix[i] = product of nums[0..i-1]
//         prefix[0] = 1;                           // nothing to left of index 0
//         for (int i = 1; i < n; i++)
//             prefix[i] = prefix[i-1] * nums[i-1];

//         // Build suffix: suffix[i] = product of nums[i+1..n-1]
//         suffix[n-1] = 1;                         // nothing to right of last index
//         for (int i = n-2; i >= 0; i--)
//             suffix[i] = suffix[i+1] * nums[i+1];

//         // Combine
//         for (int i = 0; i < n; i++)
//             answer[i] = prefix[i] * suffix[i];

//         return answer;
//     }
// };




// OPTIMAL — O(n) time, O(1) extra space (output not counted) ✓
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);

        // ── Phase 1: fill answer with prefix products ──
        answer[0] = 1;                             // nothing to left of 0
        for (int i = 1; i < n; i++)
            answer[i] = answer[i-1] * nums[i-1]; // left product

        // ── Phase 2: multiply in suffix products from right ──
        int R = 1;                                  // running right product
        for (int i = n-1; i >= 0; i--) {
            answer[i] *= R;  // multiply prefix already in answer[i] by suffix R
            R *= nums[i];    // extend R for next iteration (going left)
        }

        return answer;
    }
};