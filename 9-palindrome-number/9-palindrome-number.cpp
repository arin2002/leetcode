class Solution {
public:
    bool isPalindrome(int x) {
    int temp = x;
    int rem;
    int long sum = 0;

    while (x != 0)
    {
        rem = x % 10;
        sum = sum * 10 + rem;
        x /= 10;
    }

    if (temp == sum && sum>=0)
        return true;
    else
        return false;
    }
};