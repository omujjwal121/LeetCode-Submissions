class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s=to_string(low);
        char dig = '1';
        for(auto &c:s)
        {
            c=dig;
            dig++;
        }
        while(stoi(s)<low)
        {
            if(s.length() == 9 and s.back()=='9') break;
            if(s.back() == '9')
            {
                char dig = '1';
                int n = s.length();
                s = "";
                while(n--)
                {
                    s+=dig;
                    dig++;
                }
                s+=dig;
            }
            else for(auto &c:s) c++;
        }
        while(stoi(s)>=low and stoi(s)<=high)
        {
            ans.push_back(stoi(s));
            if(s.length() == 9 and s.back()=='9') break;
            if(s.back() == '9')
            {
                char dig = '1';
                int n = s.length();
                s = "";
                while(n--)
                {
                    s+=dig;
                    dig++;
                }
                s+=dig;
            }
            else for(auto &c:s) c++;
        }
        return ans;
    }
};