class Solution {
public:
    vector<string> sortPeople(vector<string>& a, vector<int>& b) {
        vector<string> ans;
        vector<pair<int,string>> vp;
        
        int n = a.size();
        for(int i = 0; i<n; i++){
            vp.push_back(make_pair(b[i],a[i]));
        }
        
        sort(vp.rbegin(),vp.rend());
        for(int i = 0; i<n; i++)
            ans.push_back(vp[i].second);
        
        return ans;
    }
};