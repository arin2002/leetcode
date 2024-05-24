class Solution {

    int dfs(int idx, vector<string> &words, vector<int>& score, vector<int> &cnt){

        if(idx == words.size())
        {
            return 0;
        }

        bool isPoss = true;
        int sum = 0;
        vector<int> cnt1 = cnt;

        for(int i = 0; i < words[idx].length(); i++)
        {
            char ch = words[idx][i];
            if(cnt1[ch - 'a'] > 0)
            {
                sum += score[ch - 'a'];
                cnt1[ch - 'a']--;
            }
            else
            {
                sum = 0;
                isPoss = false;
                break;
            }
        }

        int take = 0;
        if(isPoss)
        {
            take = sum + dfs(idx + 1, words, score, cnt1);
        }

        int ntake = dfs(idx + 1, words, score, cnt);
        return max(ntake, take);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = letters.size();
        vector<int> cnt(27, 0);

        for(int i = 0; i < n; i++)
        {
            cnt[letters[i] - 'a'] ++;
        }

        return dfs(0, words, score, cnt);   
    }
};
