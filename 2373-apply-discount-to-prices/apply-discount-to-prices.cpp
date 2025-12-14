class Solution {
public:
    string discountPrices(string sen, int dis) {
        int n = sen.length();
        string ans;
        int i=0;
        while(i<n)
        {
            string temp;
            while(i<n and sen[i]!=' ')
            {
                temp+=sen[i];
                i++;
            }
            if(temp[0] == '$')
            {
                string num;
                bool f = true;
                for(int j=1;j<temp.length();j++)
                {
                    if(temp[j]<'0' or temp[j]>'9')
                    {
                        f = false;
                        break;
                    }
                    num+=temp[j];
                }
                if(f == false or num.length()==0) ans+=temp+' ';
                else
                {
                    long long price = stoll(num);
                    double new_price = (price*(100-dis))/ double(100);
                    ans+='$';
                    int p=0;
                    while(to_string(new_price)[p]!='.')
                    {
                        ans+=to_string(new_price)[p];
                        p++;
                    }
                    ans+=to_string(new_price)[p];
                    ans+=to_string(new_price)[p+1];
                    ans+=to_string(new_price)[p+2];
                    ans+=to_string(new_price)[p+3];
                    if(ans.back()<'5') ans.pop_back();
                    else
                    {
                        ans.pop_back();
                        ans[ans.length()-1]++;
                    }
                    ans+=' ';
                }
            }
            else ans+=temp+' ';
            i++;
        }
        ans.pop_back();
        return ans;
    }
};