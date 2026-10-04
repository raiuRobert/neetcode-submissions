class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);     // default 0 = "no warmer day"
        stack<int> st;                // indices of days still waiting

        for (int i = 0; i < n; i++) {
            // today answers every waiting day that is colder
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();
                answer[prev] = i - prev;
            }
            st.push(i);               // today now waits for its own warmer day
        }

        return answer;
    }
};