class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {
              if (numSet.count(n - 1)) continue;      // 1. not a start → skip

            int length = 1;                         // 2. it's a start → count forward
            while (numSet.count(n + length)) {
                length++;
            }

            longest = max(longest, length);         // 3. keep the best
        }

        return longest;
    }
};