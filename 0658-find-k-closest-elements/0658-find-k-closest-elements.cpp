class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push({abs(arr[i]-x),arr[i]});
        }
        
        while(k!=0){
            cout<<pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};