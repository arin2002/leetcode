class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sent) {
        unordered_set<string> s;
        for(auto word:dictionary)s.insert(word);
        sent+=" ";
        int n= sent.size();
        bool found= false;
        string temp;
        int start;
        for(int i=0;i<sent.length();i++){
            found=false;
            temp.clear();
            while(sent[i]!=' '){
                temp+=sent[i];
                if(!found){
                    if(s.find(temp)!=s.end()){
                        found=true;
                        start=i+1;
                    }
                }
                i++;
            }
            if(found){
                sent.erase(start,i-start);
                i=start;
            }
        }
        n=sent.length();
        sent.erase(n-1,1);
        return sent;
    }
};
