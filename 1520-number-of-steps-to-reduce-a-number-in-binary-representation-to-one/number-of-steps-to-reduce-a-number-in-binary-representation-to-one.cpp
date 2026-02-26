class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s!="1")
        {
            if(s.back() == '0') s.pop_back();
            else
            {
                int i = s.length()-1;
                while(i>=0)
                {
                    if(s[i]=='1') s[i] = '0';
                    else
                    {
                        s[i] = '1';
                        break;
                    }
                    i--;
                }
                if(i == -1) s = "1"+s;
            }
            ans++;
        }
        return ans;
    }
};