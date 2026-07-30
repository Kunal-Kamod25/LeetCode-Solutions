// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int water = 0;
//         int sz = height.size();
        
//         for(int i = 0; i < sz; i ++) {
//             int lftMax = 0 , rtgMax = 0;

//             for(int j = i; j >= 0; j--) {
//                 lftMax = max(lftMax , height[j]);
//             }

//             for(int j = i; j < sz ; j++) {
//                 rtgMax = max(rtgMax , height[j]);
//             }

//             water += min(lftMax , rtgMax) - height[i];
//         }// for
//         return water;
//     }
// };




// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();

//         vector<int> lftMax(n), rtgMax(n);

//         lftMax[0] = height[0];
//         for(int i = 1; i < n; i++) {
//             lftMax[i] = max(lftMax[i - 1], height[i]);
//         }

//         rtgMax[n - 1] = height[n - 1];
//         for(int i = n - 2; i >= 0; i--) {
//             rtgMax[i] = max(rtgMax[i + 1], height[i]);
//         }

//         int water = 0;

//         for(int i = 0; i < n; i++) {
//             water += min(lftMax[i], rtgMax[i]) - height[i];
//         }

//         return water;
//     }
// };//K


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while(left < right) {
            if(height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};