class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto val:arr1){
            while(st.find(val)==st.end() && val>0){
                st.insert(val);
                val = val/10;
            }
        }

        int ans = 0;
        for(auto val:arr2){
            while(st.find(val)==st.end() && val>0){
                val = val/10;
            }
            if(val>0){
                //log10(val)+1 = number of digits in val
                ans = max(ans,(int)(log10(val)+1));
            }
        }
        return ans;
    }
};
