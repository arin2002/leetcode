class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
//         priority_queue<int> pq(nums.begin(),nums.end());
        
//         int a = pq.top()-1;
//         pq.pop();
//         int b = pq.top()-1;
//         pq.pop();
        
        int a = INT_MIN, b = INT_MIN;
        for(auto it : nums){
            if(a < it){
                b = a;
                a = it;
            }
            else if(b < it)
                b = it;
        }
        cout<<a<<" "<<b<<endl;
        a--;
        b--;
        
        return a*b;
    }
};