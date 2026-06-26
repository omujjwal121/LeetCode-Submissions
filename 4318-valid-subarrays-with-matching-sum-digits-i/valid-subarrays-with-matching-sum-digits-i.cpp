class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            long long sum = 0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                if(sum%10 !=x) continue;
                string temp = to_string(sum);
                int first = temp[0] - '0';
                int last = temp.back() - '0';
                if(first == x and last == x) ans++;
            }
        }
        return ans;
    }
};