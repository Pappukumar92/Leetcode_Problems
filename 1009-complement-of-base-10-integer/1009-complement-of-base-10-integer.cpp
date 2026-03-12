class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string b = "";
        while(n > 0){
            b = char((n % 2) + '0') + b;
            n /= 2;
        }
        for(int i = 0; i < b.size(); i++){
            if(b[i] == '0') b[i] = '1';
            else b[i] = '0';
        }
        int ans = 0;
        for(char c : b){
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }
};