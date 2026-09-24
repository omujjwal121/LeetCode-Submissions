class Solution {
    public int smallestIndex(int[] nums) {
        for(int i=0;i<nums.length;i++)
        {
            int digits = 0;
            int temp = nums[i];
            while(temp>0)
            {
                digits+=temp%10;
                temp/=10;
            }
            if(digits == i) return i;
        }
        return -1;
    }
}