class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = (int)heights.size() - 1;
        int best = 0;

        while (left < right) {
            int water = min(heights[left], heights[right]) * (right - left);
            best = max(best, water);

            if (heights[left] < heights[right]) {
                left++;          // left is the shorter wall → it can't do better
            } else {
                right--;         // right is shorter (or equal) → drop it
            }
        }

        return best;
    }
};