class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        int size = m*n;
        vector<int>arr;
        for(int i =0; i<m; i++)
        {
            for(int j =0;j<n;j++)
            {
                arr.push_back(grid[i][j] % mod);
            }
        }
        vector<int>prefix(size,1),suffix(size,1);
        for(int i=1;i<size;i++)
        {
            prefix[i]=(prefix[i-1]*arr[i-1] % mod);
        }
        for(int i =size-2;i>=0;i--)
        {
            suffix[i]=(suffix[i+1]*arr[i+1] % mod);
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i =0;i<size;i++)
        {
            int val =(prefix[i]*suffix[i]) % mod;
            ans[i/n][i%n] = val;
        }
        return ans;
    }
};