class Solution {
    public int missingMultiple(int[] nums, int k) {
        Arrays.sort(nums);
        int temp = k;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]>temp) return temp;
            else if(nums[i] == temp)
            {
                temp+=k;
            }
        }
        return temp;
    }
}