class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> myStack;
        int current_min = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            while ((!myStack.empty()) && myStack.top().first < nums[i])
                myStack.pop();

            if ((!myStack.empty()) && nums[i] < myStack.top().first && nums[i] > myStack.top().second)
                return true;

            myStack.push({nums[i], current_min});
            current_min = current_min < nums[i] ? current_min : nums[i];
        }

        return false;
    }
};
