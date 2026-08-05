class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n<k)
        return 0;
        double maxsum=0;
        for(int i=0;i<k;i++)
        {
            maxsum += nums[i];
        }
        double currentsum = maxsum;
        for(int i=k;i<n;i++)
        {
            currentsum += nums[i]-nums[i-k];
            maxsum = max(maxsum,currentsum);
        }
        return maxsum/k;
    }
};