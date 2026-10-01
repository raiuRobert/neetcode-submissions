class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = { {')', '('}, {']', '['}, {'}', '{'} };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);                          // opener → remember it
            } else {
                if (st.empty()) return false;        // closer with nothing open
                if (st.top() != match[c]) return false; // wrong type
                st.pop();                            // matched → close it
            }
        }

        return st.empty();                           // anything left open?
    }
};