class Solution {
public:
    void move90Degrees(vector<vector<char>>& res,vector<vector<char>>& box){
        for(int i=0;i<box.size();i++){
            for(int j=0;j<box[i].size();j++){
                res[j][box.size()-1-i] = box[i][j];
            }
        }
    }
    void moveStones(vector<vector<char>>& box){
        for(int i=0;i<box.size();i++){
            int pos = box[i].size()-1;
            for(int j=box[i].size()-1;j>=0;j--){
                if(box[i][j]=='#'){
                    box[i][pos] = '#';
                    if(pos!=j)
                        box[i][j] = '.';
                    pos--;
                }
                else if(box[i][j] == '*'){
                    pos = j-1;
                }
            }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> res(box[0].size(),vector<char>(box.size(),'.'));
        moveStones(box);
        move90Degrees(res,box);
        return res;
    }
};
