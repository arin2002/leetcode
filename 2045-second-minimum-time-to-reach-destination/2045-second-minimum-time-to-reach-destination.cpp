class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adjList[n + 1];

        for(auto it : edges){
            int from = it[0];
            int to = it[1];

            adjList[to].push_back(from);
            adjList[from].push_back(to);
        }

        vector<int> dist1(n + 1 , INT_MAX);
        vector<int> dist2(n + 1 , INT_MAX);

        queue<pair<int , int>> qu;
        qu.push({0 , 1});

        while(!qu.empty()){
            int currDist = qu.front().first;
            int topNode = qu.front().second;

            qu.pop();

            if(currDist <= dist1[topNode]){
                dist1[topNode] = currDist;
            }else if(currDist < dist2[topNode]){
                dist2[topNode] = currDist;
            }else{
                continue;
            }

            // If you reach to a city (topNode) and the signal is red you have to wait till the signal gets green

            // This considerarion is made because it is given that we'll start with green signal
            // if currDist / change == even the signal is green dont need to do anything
            // else add wait time == change - (currDist % change) to the currDist 

            // It is odd
            if(((currDist / change) % 2)){
                currDist += (change - (currDist % change));
            }

            for(auto it : adjList[topNode]){
                int nextNode = it;
                int newDist = currDist + time;

                if(newDist<= dist1[it] || newDist < dist2[it]){
                    qu.push({newDist , it});
                }

            }
        }

        return dist2[n];
    }
};
