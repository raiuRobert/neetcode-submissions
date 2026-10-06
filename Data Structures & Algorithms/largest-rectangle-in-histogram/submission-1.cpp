class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st;   // (start index, height), heights increasing

        for (int i = 0; i < n; i++) {
            int start = i;

            // current bar is shorter → taller bars on top can't extend further right
            while (!st.empty() && st.top().second > heights[i]) {
                auto [idx, h] = st.top();
                st.pop();
                maxArea = max(maxArea, h * (i - idx));
                start = idx;            // current bar can extend left to here
            }

            st.push({start, heights[i]});
        }

        // remaining bars extend all the way to the right end
        while (!st.empty()) {
            auto [idx, h] = st.top();
            st.pop();
            maxArea = max(maxArea, h * (n - idx));
        }

        return maxArea;
    }
};