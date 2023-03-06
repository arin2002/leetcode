class Solution {
public:
    
//     int solve(int i, string &s){
        
//         int count = 0;
//         for(int j = 0; j<s.size(); j++){
//             if(s[j] == '1')
//                 count += abs(j-i);
//         }
        
//         return count;
//     }
    
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        
        int travel = 0, ones = 0;
        for(int i = 0; i<boxes.size(); i++){
            travel += ones;
            ans[i] += travel;
            if(boxes[i] == '1')
                ones++;
        }
        
        travel = 0, ones = 0;
        for(int i = boxes.size()-1; i>=0; i--){
            travel += ones;
            ans[i] += travel;
            
            if(boxes[i] == '1')
                ones++;
        }
        
        return ans;
    }
};