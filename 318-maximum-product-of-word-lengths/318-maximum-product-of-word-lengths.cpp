class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(),ans = 0;
        vector<int> v(n,0);
        
        for(int i = 0; i<n;i++)
        {
            string s = words[i]; int num =0;
            for(int j = 0; j<words[i].length(); j++)
            {
                // converted to a integer
                int x = s[j] - 'a';
                num|= 1<<x;
            }
            v[i] = num;
        }
        
        for(int i = 0; i <n-1;i++)
        {
            for(int j =i+1;j<n; j++)
            {
                int a = v[i]&v[j];
                if(a == 0)
                {
                    int x = words[i].length()*words[j].length();
                    ans = max (ans,x);
                }
            }
        }
        
        return ans;
    }
};