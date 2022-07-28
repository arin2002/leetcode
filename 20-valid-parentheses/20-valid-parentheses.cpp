class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> stk;

        for (int i = 0; i < n; i++)
        {
            // if(s[i]=='(' || s[i]=='{' || s[i]=='[' || stk.empty())

            if (!stk.empty() && stk.top() == '(' && s[i] == ')')
            {
                stk.pop();
                continue;
            }
            else if (!stk.empty() && stk.top() == '{' && s[i] == '}')
            {
                stk.pop();
                continue;
            }
            else if (!stk.empty() && stk.top() == '[' && s[i] == ']')
            {
                stk.pop();
                continue;
            }

            stk.push(s[i]);
        }
        
        if (stk.empty() && n > 1)
            return true;
        else
            return false;
    }
};