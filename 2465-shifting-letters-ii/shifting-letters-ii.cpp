class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>v(n+1, 0);
        for(auto c:shifts)
        {
            if(c[2] == 1)
            {
                v[c[0]]++;
                v[c[1]+1]--;
            }
            else
            {
                v[c[0]]--;
                v[c[1]+1]++;
            }
        }
        int carry = 0;
        for(int i=0;i<n;i++)
        {
            carry+=v[i];
            int p = s[i] - 'a' + carry;
            p%=26;
            if(p<0) p = 26+p;
            s[i] = char(97+p);
        }
        return s;
    }
};