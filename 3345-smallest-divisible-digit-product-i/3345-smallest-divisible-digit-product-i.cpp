class Solution {
public:
    int smallestNumber(int n, int t)
    {
        for (int i = n; ; i++) 
        {
            int product = 1;
            string s = to_string(i);
            for (char c : s) {
                product *= (c - '0');
            }
            if (product % t == 0) 
            {
                return i;
            }
        }
    }
};