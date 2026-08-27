class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int i = 0;

        while (i < n) {
            int c = target[i] - 'a';

            if (cnt[c] == 0)
                break;

            cnt[c]--;
            i++;
        }

        if (i == n) {
            i--;
            cnt[target[i] - 'a']++;
        }

        while (i >= 0) {
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] == 0)
                    continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                cnt[c]--;

                for (int j = 0; j < 26; j++)
                    ans += string(cnt[j], char('a' + j));

                return ans;
            }

            if (i > 0)
                cnt[target[i - 1] - 'a']++;

            i--;
        }

        return "";
    }
};