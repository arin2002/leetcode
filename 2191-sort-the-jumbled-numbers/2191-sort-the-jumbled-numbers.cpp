class Solution {
public:
    int mappedValue(vector<int>& mapping, int num) {
        if (num == 0) return mapping[0];
    
        int newNum = 0;
        int multiplier = 1;
        
        while (num > 0) {
            int digit = num % 10;
            newNum += mapping[digit] * multiplier;
            multiplier *= 10;
            num /= 10;
        }
        return newNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> arr(nums.size());

        for(int i=0; i<nums.size(); i++)
            arr[i] = {mappedValue(mapping, nums[i]), i};
        
        sort(arr.begin(), arr.end(), [&](auto a, auto b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> sortedArr;
        for(auto el : arr)
            sortedArr.push_back(nums[el.second]);
            
        return sortedArr;
    }
};
