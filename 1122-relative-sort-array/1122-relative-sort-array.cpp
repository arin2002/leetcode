class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> ump;
        sort(arr1.begin(),arr1.end());
        int n = arr1.size();
        
        for(int i = 0; i<arr2.size(); i++){
            ump[arr2[i]] = i;
    
        }
        
        for(int i = 0; i<arr1.size(); i++){
            if(ump.find(arr1[i]) == ump.end())
                ump[arr1[i]] = n++;
        }
        
        sort(arr1.begin(),arr1.end(),[&](int a, int b){    
            return ump[a]<ump[b];
        });
        
        return arr1;
    }
};