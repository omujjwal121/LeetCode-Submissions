class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scoree) {
        map<char, int> mp;
        for(auto c: letters) mp[c]++;
        int n = words.size();
        int ans = 0;
        queue<pair<map<char, int>, vector<int>>> q;
        q.push({mp, {0, 0}});
        
        while(q.size())
        {
            map<char, int> temp_map = q.front().first;
            int ind = q.front().second[0];
            int score = q.front().second[1];
            q.pop();
            ans = max(ans, score);
            if(ind<n)
            {
                q.push({temp_map, {ind+1, score}});
                string s = words[ind];
                bool f = true;
                int temp_score = 0;
                for(auto c:s)
                {
                    temp_map[c]--;
                    temp_score+=scoree[c-'a'];
                    if(temp_map[c]<0)
                    {
                        f = false;
                        break;
                    }
                }
                if(f) q.push({temp_map, {ind+1, score+temp_score}});
            }
        }
        return ans;
    }
};