class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto it: moves){
            if(it == 'R')
                y+=1;
            else if(it == 'L')
                y-=1;
            else if(it == 'U')
                x-=1;
            else
                x+=1;
        }
        
        if(x || y)
            return 0;
        
        return 1;
    }
};