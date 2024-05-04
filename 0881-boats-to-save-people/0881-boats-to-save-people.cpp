class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(), low = 0, high = n-1, ans = 0;
        
        while(low<=high){
            int a = people[low], b = people[high];
            
            if(a+b <= limit){
                low++;
            }
            
            high--;
            ans++;
        }
        
        return ans;
    }
};