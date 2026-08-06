class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; i <= n + 10; i++) {
            int p = (i < 10) ? i : (i == 100 ? 0 : (i / 10) * (i % 10));
            if (p % t == 0) return i;
        }
        return n;
    }
};