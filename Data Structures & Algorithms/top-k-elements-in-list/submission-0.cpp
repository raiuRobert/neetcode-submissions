class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //step 1: number -> frequency
        unordered_map<int, int> count;
        for (int n: nums)
        count[n]++;

        //step 2: freq -> nr with that freq
        vector<vector<int>> buckets(nums.size()+1);
        for (const auto& [num, freq] : count)
        buckets[freq].push_back(num);

        //step 3 : highest freq to lowest, k numbers

        vector<int> result;
        for (int i=buckets.size()-1; i>0; i--)
        {
            for (int num :buckets[i])
            {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }
        return result;
    }
};
