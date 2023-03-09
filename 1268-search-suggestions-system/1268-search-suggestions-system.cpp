class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        
        sort(products.begin(),products.end());
        
        string search;
        for(int i = 0; i<searchWord.size(); i++){
            search += searchWord[i];
            
            vector<string> temp;
            for(auto &it : products){
                if(temp.size() == 3)
                    break;
                
                string t;
                for(int j = 0; j<search.size() && j<it.size(); j++)
                    t+=it[j];
                
                if(search == t)
                    temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};