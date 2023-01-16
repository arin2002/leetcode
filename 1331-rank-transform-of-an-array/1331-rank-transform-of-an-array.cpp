class Solution {
public:
    
//     int bs(int k, vector<int> &temp){
        
//         int l = 0,  r = temp.size()-1, ans = 0;
        
//         while(l<=r){
//             int mid = (l+r)/2;
            
//             if(temp[mid] == k){
//                 ans = mid+1;
//                 r = mid-1;
//             }
            
//             else if(temp[mid]<k){
//                 l = mid+1;
//             }
//             else{
//                 r = mid-1;
//             }
//         }
//         return ans;
//     }
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr, ans;
        
        unordered_map<int,int> ump;
        
        int j = 1;
        sort(temp.begin(),temp.end());
        for(auto it : temp){
            auto i = ump.find(it);
            if(i == ump.end()){
                ump[it] = j++;
            }
        }        
        for(auto it : arr){
            ans.push_back(ump[it]);
        }
        
        return ans;
    }
};