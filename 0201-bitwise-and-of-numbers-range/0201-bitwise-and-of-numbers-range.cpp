class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*int ans=left;
        for(int i=left+1;i<=right;i++)
        {
            ans=ans&i;
            if(ans==0)
            {
                return 0;
            }
        }
        return ans;
        brute force
        */
        int count=0;
        while(left!=right)
        {
            left=left>>1;//or left=left/2 //right shift left and right
            right=right>>1;//or right=right/2
            count++;
        }
        return left<<count;//or right <<count bhi karsakter hai kyuki dono equal hi hai
    }
};