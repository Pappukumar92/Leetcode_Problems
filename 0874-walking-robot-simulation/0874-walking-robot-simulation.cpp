class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(int i = 0; i < obstacles.size(); i++)
        {
            obs.insert({obstacles[i][0], obstacles[i][1]});
        }
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        int x = 0, y = 0;
        int dir = 0;
        int ans = 0;

        for(int i = 0; i < commands.size(); i++)
        {
            int cmd = commands[i];

            if(cmd == -1)
            {
                dir = (dir + 1) % 4;
            }
            else if(cmd == -2)
            {
                dir = (dir + 3) % 4;
            }
            else
            {
                for(int step = 0; step < cmd; step++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(obs.count({nx, ny}))
                    break;
                    x = nx;
                    y = ny;

                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};