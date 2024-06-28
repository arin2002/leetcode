class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       unordered_map<int,int>mp;
       for(auto x:roads){
          mp[x[0]]++;
          mp[x[1]]++;
       }

       vector<pair<int,int>>vp;
       for(auto x:mp){
           vp.push_back({x.second,x.first});
       }

       sort(vp.begin(),vp.end());

       int k=n;
       for(int i=vp.size()-1;i>=0;i--){
           mp[vp[i].second]=k;
           k--;
       }

       long long sum=0;
       for(auto x:roads){
           sum+=mp[x[0]];
           sum+=mp[x[1]];
       }
       return sum;
    }
};
