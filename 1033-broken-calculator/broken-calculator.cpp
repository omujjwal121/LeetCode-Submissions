class Solution {
public:
    int brokenCalc(int n, int target) {
        int ans = 0;
        while(n<target)
        {
            if(target%2==0)target/=2;
            else target+=1;
            ans++;
        }
        ans+=n-target;
        return ans;
    }
};