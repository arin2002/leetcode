class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i=0; i<paths.size(); i++)
        {
            string dest=paths[i][1];
            bool isdest=true;
            for(int j=0; j<paths.size(); j++)
                if(paths[j][0]==paths[i][1])
                {
                    isdest=false;
                    break;
                }
            if(isdest)
                return paths[i][1];
        }
        return "";
    }
};
