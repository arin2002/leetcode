class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string a ="", b = "";
        
        for(int i =0; i<n1;i++)
            a+=word1[i];
        
        for(int i =0; i<n2; i++)
            b+=word2[i];
        
        n1 = a.length();
        n2 = b.length();
        
        if(n1!=n2)
            return false;
        
        for(int i =0; i<n1; i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
};