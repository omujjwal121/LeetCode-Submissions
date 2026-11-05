class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans = 0;
        long cnt = 0;
        long n = nums.length;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minK || nums[i]>maxK)
            {
                ans+=(cnt*(cnt+1))/2;
                cnt = 0;
            }
            else cnt++;
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
    }
}