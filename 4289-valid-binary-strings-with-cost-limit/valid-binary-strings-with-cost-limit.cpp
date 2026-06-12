class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        queue<pair<string, pair<int ,int>>>q;                              // sum, string, index
        string s;
        s.append(n, '0');
        q.push({s,{1, 0}});
        s[0]='1';
        q.push({s,{1, 0}});
        map<string, bool>mp;
        while(q.size())
        {
            string temp = q.front().first;
            int ind = q.front().second.first;
            int sum = q.front().second.second;
            q.pop();
            if(sum<=k and mp[temp]==false) 
            {
                ans.push_back(temp);
                mp[temp] = true;
            }
            if(ind<n)
            {
                if(temp[ind]=='0')
                {
                    string tt = temp;
                    tt[ind] = '1';
                    if(temp[ind-1]!='1') q.push({tt, {ind+1, sum+ind}});
                    q.push({temp, {ind+1, sum}});
                }
                else q.push({temp, {ind+1, sum}});
            }
        }
        return ans;
    }
};