class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // STEP 1
        unordered_map<string, vector<string>> groups;

        // STEP 2
        for (const string& word : strs) {
            int count[26] = {0};
            for (char c : word) {
                count[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + '#';
            }
            groups[key].push_back(word);
        }

        // STEP 3
        vector<vector<string>> result;
        for (auto& [key, list] : groups) {
            result.push_back(list);
        }
        return result;
    }
};