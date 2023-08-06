class Solution {
public:
    int GOAL,N,K;
    int const mod=1e9+7;
    long solve(int count_song,int unique_song,vector<vector<long>>&dp){
        //base case
        if(count_song==GOAL){
            if(unique_song==N){
               return dp[count_song][unique_song]= 1;
            } 
            return 0;
        }
        if(dp[count_song][unique_song]!=-1)return dp[count_song][unique_song];
        long res=0;
        if(N>unique_song)
            res=res+((N-unique_song)*(solve(count_song+1,unique_song+1,dp)%mod))%mod;
        if(unique_song>K)
            res=res+((unique_song-K)*(solve(count_song+1,unique_song,dp)%mod))%mod;
        return dp[count_song][unique_song]=res%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        GOAL=goal;
        N=n;
        K=k;
        vector<vector<long>>dp(101,vector<long>(101,-1));
        return (int)solve(0,0,dp);
    }
};