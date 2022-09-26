class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return findParent(parent[node]);
    }
    void unionn(int a,int b){
        int u=findParent(a);
        int v=findParent(b);
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    bool equationsPossible(vector<string>& e) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto it:e){
            int a=it[0]-'a', b=it[3]-'a';char sign=it[1];
            if(sign=='='){
                unionn(a,b);
            }
        }
        for(auto it:e){
            int a=it[0]-'a', b=it[3]-'a';char sign=it[1];
            if(sign=='!' && (findParent(a)==findParent(b))){
                return false;   
            }
        }
        return true;
    }
};