class Solution {
public:
    bool judgeCircle(string moves) {
        
        int U = 0, D = 0, L = 0, R = 0;
        for(int i = 0; i < moves.size(); i++)
        {
            if(moves[i] == 'U')
                U++;
            else if(moves[i] == 'D')
                D++;
            else if(moves[i] == 'R')
                R++;
            else if(moves[i] == 'L')
                L++;
        }
        return (U == D && L == R);
    }
};