class Solution {
public:
    
    class trie
    {
        public:
        trie* next[26];
        int end;

        trie()
        {
            for(int i=0; i<26; i++)
            next[i]=NULL;
            end=0;
        }

    };
	
	//build the tree
    trie* maketree(vector<string> &s)
    {
        trie* root=new trie();
        for(int i=0; i<s.size(); i++)
        {
            trie* curr=root;
            for(int j=0; j<s[i].size(); j++)
            {
               if(curr->next[s[i][j]-'a']==NULL)
               {
                   curr->next[s[i][j]-'a']=new trie();
                   
               }
                curr=curr->next[s[i][j]-'a'];
                curr->end+=1;  // increment by one when ever any word passes this node
                   
            }
            
        }
        
        return root;
        
        
    }
    
    
    int cal(string &s, trie* &root)
    {
        trie* curr= root;
        int ans=0;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            curr= curr->next[s[i]-'a'];
            ans+= curr->end; // accumulate all the sum while moving down with each word
        }
        return ans;
        
    }
    
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        trie* root= maketree(words);
        vector<int> ans;
        for(auto i: words)
        {
            ans.push_back(cal(i,root));
        }
        return ans;
    }
};
