class Solution {
public:
    int minSteps(string s, string t) {
        
        int arr[26] = {0};
        
        for(auto it : s)
            arr[it-'a']++;
        
        int count = 0;
        
        for(auto it : t){
            // cout<<it<<" "<<arr[it-'a']<<endl;
            if(arr[it-'a'] != 0)
                arr[it-'a']--;
            
            else
                count++;
        }
        
        return count;
    }
};