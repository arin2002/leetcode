class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        
        for(auto &it: trust){
            indegree[it[1]]++;
            indegree[it[0]]--;
        }
        
        for(int i = 1; i<indegree.size(); i++){
            if(indegree[i] == n-1)
                return i;
        }
        
        return -1;
    }
};