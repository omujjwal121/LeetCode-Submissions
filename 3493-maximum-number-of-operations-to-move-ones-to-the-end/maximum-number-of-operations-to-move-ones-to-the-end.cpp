class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int i=s.length() -1, n = s.length();
        int one = count(s.begin(), s.end(), '1');
        while(i>=0)
        {
            if(s[i] == '1') one--;
            else
            {
                ans+=one;
                while(i>=0 and s[i] == '0') i--;
                i++;
            }
            i--;
        }
        return ans;
    }
};