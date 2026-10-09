class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};   // 1-indexed
            } else if (sum < target) {
                left++;                         // need a bigger number
            } else {
                right--;                        // need a smaller number
            }
        }

        return {};   // never reached: a solution is guaranteed
    }
};
