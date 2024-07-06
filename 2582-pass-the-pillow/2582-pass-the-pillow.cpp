class Solution {
public:
    int passThePillow(int n, int time) {
        int current = 1, flag  = 1, passed = 0;
//         for(int i = 1; i<=n; i++){
//             v.push_back(i);
//         }
        
//         while(time){
//             if(i == v.size()-1){
                
//             }
//             else{
                
//             }
//         }
        
        while(passed<time){
            current += flag;
            
            if(current == n || current == 1)
                flag = -flag;
            
            passed++;
        }
        
//         if(time == n-1)
//             return n;
        
//         if(time>n)
//             return time%n + time;
        
        return current;
    }
};