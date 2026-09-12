class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int ans=0;
        int low=0;
        long long pro=1;
        for(int high=0;high<nums.size();high++){
            pro*=nums[high];
            while(pro>=k){
                pro/=nums[low];
                low++;
            }
            ans+=high-low+1;
            
        }
        return ans;
        
    }
};