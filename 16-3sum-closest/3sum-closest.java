class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int maxi = Integer.MAX_VALUE;
        int n = nums.length;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int sum = (nums[i]+nums[j]+nums[k]);
                    if(Math.abs(target - sum) < maxi)
                    {
                        maxi = Math.abs(target - sum);
                        ans = sum;
                    }
                }
            }
        }
        return ans;
    }
}