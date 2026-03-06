class Solution {
public:
    bool checkZeroOnes(string s) {
        int c1 =0,c0=0;
        int m1=0,m0=0;
        for(int i = 0;i<s.length();i++)
        {
        if(s[i]=='1')
        {
            c1++;
            c0=0;
            if(c1>m1)
            {
                m1=c1;
            }
        }
        else
        {
            c0++;
            c1=0;
            if(c0>m0)
            {
                m0=c0;
            }
        }
    }
    if(m1>m0)
    return true;
    else
    return false;
}
};