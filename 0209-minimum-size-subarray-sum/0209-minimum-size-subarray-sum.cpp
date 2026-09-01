class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int minlenwindow=INT_MAX;
        int sum=0;
        for(int high=0;high<nums.size();high++){
            sum+=nums[high];
            while(sum>=target){
                minlenwindow=min(minlenwindow,high-low+1);
                sum-=nums[low];
                low++;
            }

        }
        return minlenwindow == INT_MAX? 0: minlenwindow;
    }
};