// Optimal — O(n) time, O(1) space  ✓
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // write position for next non-zero

        // Phase 1: compact all non-zeros to the front
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast]; // write non-zero at slow
                slow++;                  // advance write head
            }
            // if zero: fast auto-advances via for loop, slow stays
        }

        // Phase 2: fill remaining positions with 0
        for (int i = slow; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};