class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int arr[26]={0};
        int n =words.size();
        if(n==1) {
            return 1;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<words[i].length();j++) {
                arr[words[i][j]-'a']++;
            }
        }

        for(int i=0;i<26;i++) {
            cout<<arr[i]<<endl;
            if(arr[i]!=0 && arr[i]%words.size()!=0) {
                return 0;
            }
        }
        return 1;
        
    }
};
