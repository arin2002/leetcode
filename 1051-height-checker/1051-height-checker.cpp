class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v;
        int n = heights.size();
        for(auto i : heights)
            v.push_back(i);
        
        sort(v.begin(),v.end());
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(v[i] != heights[i])
                count++;
        }
        
        return count;
    }
};