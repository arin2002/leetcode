class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> xor_val(size);
        vector<int> ans;

        xor_val[0]=arr[0];
        for(int i=1; i<size ; i++){
            xor_val[i] = xor_val[i-1]^arr[i];
        }

        int left;
        int right;
        for(auto query: queries){
            left = query[0];
            right = query[1];

            if(left == 0) ans.push_back(xor_val[right]);
            else{
                ans.push_back(xor_val[left-1]^xor_val[right]);
            }
        }
        return ans;

    }

};