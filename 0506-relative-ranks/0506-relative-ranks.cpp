class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size(), i = 1;
        vector<pair<int,int>> vp;
        
        for(int i = 0; i<n; i++){
            vp.push_back({score[i],i});
        }
        
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        
        vector<string> ans(n);
        
        for(auto &[a,b]: vp){
            string num = to_string(i);
            
            cout<<a<<" "<<b<<endl;
            if(i == 1){
                num = "Gold Medal";
            }
            else if(i == 2){
                num = "Silver Medal";
            }
            else if(i == 3){
                num = "Bronze Medal";
            }
            
            ans[b] = num;
            i++;
        }
        
        return ans;
    }
};