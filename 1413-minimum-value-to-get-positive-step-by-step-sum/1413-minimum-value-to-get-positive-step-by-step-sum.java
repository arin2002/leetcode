class Solution {
    public int minStartValue(int[] nums) {
        int [] cumsum = new int[nums.length];
        cumsum[0]= nums[0];
        for(int i=1;i<nums.length;i++)
        {
            cumsum[i] = cumsum[i-1] + nums[i];
        }
        int min = Integer.MAX_VALUE;
        for(int i : cumsum)
            min = Math.min(min,i);
        
        return min < 0 ? Math.abs(min)+1 : 1;
    }
}
