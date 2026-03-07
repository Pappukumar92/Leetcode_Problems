class Solution {
public:
    int minFlips(string s) {
        int n=s.size(),a=0,b=0,res=n;
        s+=s;
        for(int i=0;i<2*n;i++){
            if(s[i]!=(i%2?'1':'0')) a++;
            if(s[i]!=(i%2?'0':'1')) b++;

            if(i>=n){
                if(s[i-n]!=((i-n)%2?'1':'0')) a--;
                if(s[i-n]!=((i-n)%2?'0':'1')) b--;
            }
            if(i>=n-1) res=min(res,min(a,b));
        }
        return res;
    }
};