class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                          // smallest is positive → no sum can be 0
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // same fixed value → skip duplicates

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;                                  // too small → need bigger
                } else if (sum > 0) {
                    right--;                                 // too big → need smaller
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;  // skip duplicate lefts
                }
            }
        }

        return result;
    }
};

