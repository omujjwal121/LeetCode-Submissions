class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = count(nums.begin(), nums.end(), 1);
        int maxi = 0;
        int right = 0, left = (n-one+1)%n;
        int cnt = 0; for(int i=left;i<n and i>0;i++) if(nums[i]==1) cnt++;
        while(right<n)
        {
            if(nums[right]==1) cnt++;
            maxi = max(maxi, cnt);
            right++;
            if(nums[left]==1) cnt--;
            left = (left+1)%n;
        }
        return one-maxi;
    }
};