class Solution {
public:
    int countSeniors(vector<string>& d) {
        int count = 0;
        for(auto &it: d){
            int age = (it[11]-'0')*10 + (it[12]-'0');
            
            if(age>60)
                count++;
        }
        
        return count;
    }
};