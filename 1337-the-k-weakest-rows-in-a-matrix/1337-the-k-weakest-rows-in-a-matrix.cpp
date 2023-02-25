class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        
        int j = 0;
        for(auto it : mat){
            int count = 0;
            for(auto i : it){
                if(i == 1)
                    count++;
            }
            pq.push({count,j++});
        }
        
        while(pq.size()>k)
            pq.pop();
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};