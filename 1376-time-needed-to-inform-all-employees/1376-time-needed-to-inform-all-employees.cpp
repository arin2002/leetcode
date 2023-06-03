class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n+1];
        
        for(int i = 0; i<manager.size(); i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int,int>> q;
        q.push({headId,0});        
        // cout<<informTime[headId];
        int ans = informTime[headId];
        while(!q.empty()){
            int mang = q.front().first;
            int temp = q.front().second;
            int time = informTime[mang];
            
            ans = max(ans,temp);
            // cout<<ans<<" ";
            q.pop();
            
            for(auto &it: adj[mang]){
                q.push({it,temp+time});
            }
        }
        return ans;
    }
};