// Optimal — O(n²) time, O(1) extra space (output not counted)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());          // O(n log n) — enables 2ptr + dedup
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // ── Skip duplicate values of i ──────────────────────
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // ── Early exit: smallest possible sum > 0 ───────────
            if (nums[i] > 0) break;  // sorted: everything after is also > 0

            int L = i + 1, R = n - 1;
            int target = -nums[i];    // need L+R == target

            while (L < R) {
                int sum = nums[L] + nums[R];

                if (sum == target) {
                    result.push_back({nums[i], nums[L], nums[R]});

                    // ── Skip duplicates of L and R ──────────────────
                    while (L < R && nums[L] == nums[L+1]) L++;
                    while (L < R && nums[R] == nums[R-1]) R--;

                    L++; R--;  // move both pointers inward

                } else if (sum < target) {
                    L++;       // need bigger sum
                } else {
                    R--;       // need smaller sum
                }
            }
        }
        return result;
    }
};