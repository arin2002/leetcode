class Solution {
public:

    int getIndex(string& s){
        for(int i=0;i<6;i++){
            if(s[i]=='0') return i;
        }
        return -1;
    }
    string helper(string s, int i, int j){
        char c = s[i];
        s[i]=s[j];
        s[j]=c;
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
       string s="" ;
       for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            s+=('0'+board[i][j]);
        }
       }

       unordered_map<string,int>visited;
       queue<pair<string,int>>q;
       q.push({s,0});

       while(q.size()){
        int nn=q.size();
            while(nn--){
                auto p = q.front();
                q.pop();
                string curr = p.first;
                visited[curr]=1;
                int currAns = p.second;
                cout<<curr<<" "<<currAns<<endl;
                if(curr=="123450") return currAns;
                int index = getIndex(curr);
                string temp;
                if(index!=3 && index-1>=0){
                temp = helper(curr, index, index-1) ;
                if(visited.find(temp)==visited.end()) q.push({temp, currAns+1});
                }
                if(index!=2 && index+1<curr.size()){
                temp = helper(curr, index, index+1) ;
                if(visited.find(temp)==visited.end()) q.push({temp, currAns+1});
                }
                if(index+3<curr.size()){
                temp = helper(curr, index, index+3) ;
                if(visited.find(temp)==visited.end()) q.push({temp, currAns+1});
                }
                if(index-3>=0){
                temp = helper(curr, index, index-3) ;
                if(visited.find(temp)==visited.end()) q.push({temp, currAns+1});
                }
            }
            cout<<"--------------"<<endl;
        
       }

       return -1;
    }
};
