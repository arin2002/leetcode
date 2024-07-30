class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> numb(n+1,0);
        int countb = 0;
        numb[0] = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'b'){
                countb++;
            }
            numb[i+1] = countb;
        }
        vector<int> numa(n+1 , 0);
        numa[n] = 0;
        int counta = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            if(s[i] == 'a'){
                counta++;
            }
            numa[i] = counta;
        }
        vector<int> finalAns(n+1 , 0);
        for(int i = 0 ; i < n+1 ; i++){
            finalAns[i] = numb[i] + numa[i];
        }
        int mindel = INT_MAX;
        for(int i = 0 ; i < finalAns.size() ; i++){
            if(finalAns[i] < mindel){
                mindel = finalAns[i];
            }
        }
        return mindel;
    }
};
