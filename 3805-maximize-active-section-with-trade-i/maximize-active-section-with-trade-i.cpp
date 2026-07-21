class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones = count(s.begin(), s.end(), '1');
        int ans = ones;
        int i=0;
        while(i<n)
        {
            int left = 0, right = 0, temp;
            while(i<n and s[i]=='0')
            {
                left++;
                i++;
            }
            while(i<n and s[i]=='1')
            {
                i++;
            }
            if(i<n and left and s[i]=='0')
            {
                temp = i;
                while(i<n and left and s[i]=='0')
                {
                    right++;
                    i++;
                }
                i = temp;
            }
            if(left and right) ans = max(ans, ones+left+right);
        }
        return ans;
    }
};