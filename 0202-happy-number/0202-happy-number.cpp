class Solution {
public:
    
    int find(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n/=10;
        }
        
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!= 1){
            if(st.find(n) != st.end())
                return 0;
            st.insert(n);
            
            n = find(n);
        }
        
        return true;
    }
};