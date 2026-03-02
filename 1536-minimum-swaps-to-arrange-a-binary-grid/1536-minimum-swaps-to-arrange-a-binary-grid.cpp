class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
        int n = g.size(), ans = 0;
        vector<int> t(n);
        for(int i = 0; i < n; i++)
            for(int j = n - 1; j >= 0 && g[i][j] == 0; j--)
                t[i]++;

        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && t[j] < n - i - 1) j++;
            if(j == n) return -1;
            ans += j - i;
            while(j > i) swap(t[j], t[j - 1]), j--;
        }
        return ans;
    }
};