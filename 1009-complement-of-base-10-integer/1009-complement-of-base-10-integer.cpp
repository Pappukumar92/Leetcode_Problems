class Solution {
public:
    int solve(int n, int pos){
        if(n == 0) return 0;

        int bit = n % 2;
        int flipped = 1 - bit;

        return flipped * pos + solve(n / 2, pos * 2);
    }
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        return solve(n, 1);
    }
};