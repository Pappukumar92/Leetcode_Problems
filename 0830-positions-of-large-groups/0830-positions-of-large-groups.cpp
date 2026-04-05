class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) { 
        vector<vector<int>> ans;
        int start = 0;
        for(int i = 0; i < s.size(); i++) 
        {
            if(i == s.size()-1 || s[i] != s[i+1])
            {
                int length = i - start + 1;

                if(length >= 3)
                {
                    ans.push_back({start, i});
                }
                start = i + 1;
            }
        }
        return ans;
    }
};