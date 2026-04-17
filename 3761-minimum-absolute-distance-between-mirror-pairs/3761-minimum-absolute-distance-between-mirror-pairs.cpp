class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeen; 
        int minDist = INT_MAX;
        for (int j = 0; j < (int)nums.size(); j++) {
            int rev = reverseNum(nums[j]);
            if (lastSeen.count(nums[j])) {
                minDist = min(minDist, j - lastSeen[nums[j]]);
            }
            lastSeen[rev] = j;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
private:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};