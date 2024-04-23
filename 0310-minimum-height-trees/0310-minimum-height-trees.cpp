class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans, adj[n], indegree(n);
        int mini = INT_MAX;
        
        if(n == 1)
            return {n-1};
        
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        // google question
        
        // so basically brute force will give TLE as O(n2) and our constraint don't allow us
        // hence we will try to build some intution
        // now we can see by simple observation that leaf to leaf path will be worst
        // and middle will give the best answer
        // so choose node in middle
        // and leaf can't be ans
        // ans can be atmost 2 by obs
        
        // topo sort is used leaf se jaate raho middle par aa jayenge ek point par
        // topo sort algo
        
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(indegree[i] == 1){
                indegree[i]--;
                q.push(i);
            }
        }
        
        // in total graph we need to check 2 nodes not like break if only 2 nodes left in queue
        while(n>2){
            int size = q.size();
            n -= size;
            
            while(size--){
                int node = q.front();
                q.pop();
                
                for(auto &it: adj[node]){
                    indegree[it]--;
                    
                    if(indegree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};