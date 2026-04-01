class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions)
    {
        int n = positions.size();
        vector<int> index(n);
        for(int i = 0; i < n; i++)
        index[i] = i;
        sort(index.begin(), index.end(), [&](int a, int b)
        {
            return positions[a] < positions[b];
        });
        stack<int> st;
        for(int id : index)
        {
            if(directions[id] == 'R')
            {
                st.push(id);
            }
            else
            {
                while(!st.empty() && healths[id] > 0)
                {
                    int top = st.top();
                    if(healths[top] < healths[id])
                    {
                        st.pop();
                        healths[id]--;
                        healths[top] = 0;
                    }
                    else if(healths[top] > healths[id])
                    {
                        healths[top]--;
                        healths[id] = 0;
                    }
                    else
                    {
                        st.pop();
                        healths[top] = 0;
                        healths[id] = 0;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(healths[i] > 0)
            ans.push_back(healths[i]);
        return ans;
    }
};