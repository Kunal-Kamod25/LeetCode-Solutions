class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int sz = heights.size();
        stack<int> stk;
        int maxArea = 0;

        for (int i = 0; i <= sz; i++) {

            int h = (i == sz) ? 0 : heights[i];

            while (!stk.empty() && heights[stk.top()] >= h) {

                int ht = heights[stk.top()];
                stk.pop();

                int width = stk.empty() ? i : (i - stk.top() - 1);

                maxArea = max(maxArea, ht * width);
            }

            stk.push(i);
        }

        return maxArea;
    }
};