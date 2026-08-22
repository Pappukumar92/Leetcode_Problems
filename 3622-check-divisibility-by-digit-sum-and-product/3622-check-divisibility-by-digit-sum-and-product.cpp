class Solution {
public:
    bool checkDivisibility(int n) {
        string numStr = to_string(n);
        
        long long sum = 0;
        long long product = 1;
                for (char c : numStr) {
            int digit = c - '0';
            sum += digit;
            product *= digit;
        }
        return n % (sum + product) == 0;
    }
};