class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs)
        {
            result.append(to_string(s.size()));
            result.append("#");
            result.append(s);
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;
        int i = 0;

        while(i< s.size())
        {
            int j= s.find('#',i);
            int length= stoi(s.substr(i, j-i));
            result.push_back(s.substr(j+1, length));
            i= j+1+length;
        }

        return result;
    }
};
