// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>ans;
//         int n= nums.size();
//         for(int i=0 ; i<n ; i++)
//         {
//             for(int j=i+1 ; j<n ; j++)
//             {
//                 if(nums[i] + nums[j]==target)
//                 {
//                     ans.push_back(i); //ans[0]=i;
//                     ans.push_back(j); //ans[j]=j;
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums , int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         while(left < right) {
//             int sum = nums[left] + nums[right];
//             if(sum == target) 
//                 return {left , right};
//             else if (sum < target) 
//                 left ++;
//             else
//                 right --;
//         }
//         return {};
//     }
// };


//Hash map optimal solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
