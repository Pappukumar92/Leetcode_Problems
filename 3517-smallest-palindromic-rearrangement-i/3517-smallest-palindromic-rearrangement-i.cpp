class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        string ans = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i] / 2; j++) {
                ans += (char)('a' + i);
            }

            if (count[i] % 2 == 1) {
                mid = (char)('a' + i);
            }
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());

        return ans + mid + rev;
    }
};