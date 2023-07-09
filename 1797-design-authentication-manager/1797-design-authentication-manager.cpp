class AuthenticationManager {
public:
    unordered_map<string,int> ump;
    int t = 0;
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        ump[tokenId] = currentTime+t;
    }
    
    void renew(string tokenId, int currentTime) {
        if(ump.find(tokenId) != ump.end()){
            if(ump[tokenId] <= currentTime)
                return;
            ump[tokenId] = currentTime+t;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto [a,b] : ump){
            if(b>currentTime)
                count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */