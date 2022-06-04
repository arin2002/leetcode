class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] newArray = new int[nums.length];
		//Left side even numbers
        int evenIndex = 0;
		//Rigth side odd numbers
        int oddIndex = nums.length - 1;
        for (int index = 0; index < nums.length; index++) {
            if (nums[index] % 2 == 0) {
                newArray[evenIndex] = nums[index];
                evenIndex++;
            } else {
                newArray[oddIndex] = nums[index];
                oddIndex--;
            }
        }
        return newArray;
    }
}
