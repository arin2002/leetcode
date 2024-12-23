class Solution {
    
    int getCycleSize(vector<int>& arr, int root) {
        if(root == arr[root]) return 1;
        swap(arr[root], arr[arr[root]]);
        return 1 + getCycleSize(arr, root);
    }
    
    int getSwaps(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_map<int, int> mp;
        vector<int> sec = arr;
        sort(sec.begin(), sec.end());
        for(int i=0;i<n;i++) {
            mp[sec[i]] = i;
        }
        for(int i = 0;i<n;i++) {
            arr[i] = mp[arr[i]];
        }
        for(int i=0;i<n;i++) {
            res += (getCycleSize(arr, i) - 1);
        }
        return res;
        
    }
    
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(q.size()) {
            int n = q.size();
            vector<int> temp;
            while(n--) {
                TreeNode* curr = q.front(); q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res += getSwaps(temp);
        }
        return res;
    }
};
