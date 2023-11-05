class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q;
        int count = 0, ans = 1, prev = -1;
        int n = arr.size();
        
        if(k >= n){
            return *max_element(arr.begin(),arr.end());
        }
        
        for(int i = 1; i<n; i++){
            q.push(arr[i]);
        }
        
        while(count != k){
            
            // cout<<arr[0]<<" "<<q.front()<<"\n";
            if(arr[0]<q.front()){
                q.push(arr[0]);
                arr[0] = q.front();
            }
            else{
                q.push(q.front());
            }
            
            q.pop();
            
            if(prev == arr[0]){
                count++;
            }
            else{
                prev = arr[0];
                count = 1;
            }
            
            // cout<<arr[0]<<" ";
        }
        
        return arr[0];
    }
};