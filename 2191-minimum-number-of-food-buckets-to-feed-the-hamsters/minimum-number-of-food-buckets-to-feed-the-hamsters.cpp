class Solution {
public:
    int minimumBuckets(string ham) {
        int n = ham.length();
        for(int i=0;i<n;i++)
        {
            if(ham[i] == 'H')
            {
                bool l = false, r = false;
                if(i-1>=0 and ham[i-1] == 'F') l = true;
                if(l == false)
                {
                    if(i+1<n and ham[i+1]=='.')
                    {
                        ham[i+1] = 'F';
                        r = true;
                    }
                    else if(i-1>=0 and ham[i-1]=='.')
                    {
                        ham[i-1] = 'F';
                        l = true;
                    }
                    else return -1;
                }
            }
        }
        return count(ham.begin(), ham.end(), 'F');
    }
};