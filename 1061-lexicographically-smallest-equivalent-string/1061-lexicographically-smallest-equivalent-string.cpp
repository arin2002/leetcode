class Solution {
public:
    vector<int>parent;
    int find(int x){  //find function returns the parent of set
      if(parent[x]==x){
          return x;
      }
      return parent[x]=find(parent[x]);
    }
    void union_set(int x,int y){ // make union of the set a & b if they belongs to different set
        x=find(x);
        y=find(y);
        if(x==y){                //if they belong to same set simply return.
            return;
        }
        parent[max(x,y)]=min(x,y); //making lexicographically smallest char as parent of the union set
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<s1.size();i++){ // s1[1] and s2[i] are similarto each other hence they are put in same set.
          int a=s1[i]-'a';
          int b=s2[i]-'a';
          union_set(a,b);    // make union of the set a & b if they belongs to different set
        }
        string ans;
        for(auto x:baseStr){
            char k=find(x-'a')+'a';    // here find function returns the lexographically smallest char from the set
            ans+=k;
        }
        return ans;
    }
};
