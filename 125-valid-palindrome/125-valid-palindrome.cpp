class Solution
{
    public:
        bool isPalindrome(string s)
        {

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = tolower(s[i]);
            }

            int l = 0, h = s.length() - 1;
            while (l < h)
            {

                if (!(s[l] >= 'a' && s[l] <= 'z' || s[l] >= '0' && s[l] <= '9'))
                    l++;
                else if (!(s[h] >= 'a' && s[h] <= 'z' || s[h] >= '0' && s[h] <= '9'))
                    h--;
                else if (s[l] == s[h])
                {
                    l++;
                    h--;
                }
                else
                    return false;
            }
            return true;
        }
};