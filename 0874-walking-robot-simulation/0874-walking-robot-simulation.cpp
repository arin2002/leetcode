class Solution {
public:
    
    int get_curr_dir(vector<bool>dir){
        for(int i=0;i<4;i++){
            if(dir[i]) return i;
        }
        return -1;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int,int>>hash_set; // using a set for obstacles
        for(auto i:obstacles){
            hash_set.insert({i[0],i[1]});
        }

        vector<bool>directions(4,false); // north,east,south,west
        directions[0]=true; // initially robotot is facing north

        int x = 0; // initial x coordinate
        int y = 0; // initial y coordinate

        int ans = INT_MIN; // storing the final answer

        for(int i=0;i<n;i++){
            
            if(commands[i]==-1){
               int curr_dir = get_curr_dir(directions);// what is the current direction?
               directions[curr_dir]=false;
               directions[(curr_dir+1)%4]=true;// setting the new direction
            } 
        else if(commands[i]==-2){
               int curr_dir = get_curr_dir(directions);
               directions[curr_dir]=false;
               directions[(curr_dir+3)%4]=true;
        }
        else{
            for(int j=0;j<commands[i];j++){
  

                if(directions[0]) y++;// if facing north then only y coordinate will increase
                else if(directions[1]) x++;// if facing east then only x coordinate will increase
                else if(directions[2]) y--;// if facing south then only y coordinate will decrease
                else if(directions[3]) x--;// if facing west then only x coordinate will decrease

                if(hash_set.find({x,y})!=hash_set.end()){
             // if the present coordinate is a part of obstacle then go back to previos coordinate
                    if(directions[0]) y--;
                    else if(directions[1]) x--;
                    else if(directions[2]) y++;
                    else if(directions[3]) x++;
                    
                    ans = max(ans,(x*x+y*y));
                    break;//stop since you cant move ahead of obstacle
                }   

                ans = max(ans,(x*x+y*y));   // update the answer
            }
        }
        
    }

    return ans;

} 
};
