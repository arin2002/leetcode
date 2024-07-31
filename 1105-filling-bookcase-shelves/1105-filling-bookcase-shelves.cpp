class Solution {
public:
    int dp[1001][1001];
    int solve(vector<vector<int>> &a, int height, int thickness, int i, int w){
        if(i==a.size()){
            return height;
        }
        if(dp[i][thickness]!=-1)
            return dp[i][thickness];
        // we can either place on current shelf or on next shelf
        int place = INT_MAX;
        // placing a book on current shelf will have height max of book's height or the shelf's height only if we can place it
        if(thickness+a[i][0] <= w)
            place = solve(a,max(height,a[i][1]),thickness+a[i][0], i+1, w);
        // placing on new shelf will add the the new height reached by the new shelf to the existing height
        int newShelf =  height + solve(a, a[i][1], a[i][0], i+1, w);
        return dp[i][thickness] = min(place, newShelf);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(books,0,0,0,shelfWidth);
    }
};
