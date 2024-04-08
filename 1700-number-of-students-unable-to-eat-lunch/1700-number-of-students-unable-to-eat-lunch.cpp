class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), cnt = 0;
        queue<int> q;
        
        for(auto &it: students){
            q.push(it);
        }
        
        int start = 0;
        while(!q.empty()){
            int front = q.front();
            int n = q.size();
            int type = sandwiches[start];
            q.pop();
            
            if(n == cnt)
                return n;
            
            if(front == type){
                start++;
                cnt = 0;
            }
            else{
                q.push(front);
                cnt++;
            }
        }
        
        return 0;
    }
};