class Solution
{
    public:

        int firstUniqChar(string s)
        {
            unordered_map<char, int> v;
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                auto it = v.find(s[i]);

                if (it == v.end())
                    v[s[i]] = i;
                else
                    v[s[i]] = -1;
            }

            for (int i = 0; i < n; i++)
            {
                auto it = v.find(s[i]);

                if (it->second !=-1)
                    return it->second;
            }
            return -1;
        }
};