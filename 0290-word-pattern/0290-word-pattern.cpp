class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        unordered_map<char,string> m;
        set<string> st;
        int i=0;
        string temp = "";

        // just push each word in the vector, THIS CAN BE DONE BY STRINGSTREAM IN 2 LINES
        while(i < s.size())
        {
            // ith word is empty in string s, as it is shifted in temp
            if(s[i] == ' ')
            {
                v.push_back(temp);
                temp="";
            }
            else
            {
                temp += s[i];
            }
            i++;
        }
        v.push_back(temp);

        // edge case
        if(v.size() != pattern.size()) return false;

        for(int i=0;i<pattern.size();i++)
        {
            // checking whether the pattern is already there or not
            if(m.find(pattern[i]) != m.end())
            {
                // also checking the each words
                if(m[pattern[i]] != v[i]) return false;
            }
            //its not present in the map
            else
            {
                // Check if the string is previously in set
                // If it is in set it means it is already mapped 
                if(st.count(v[i]) > 0) return false;

                // new word came so just push the value
                m[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};
