class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n);
        int left=0;
        int right=n-1;
        for (int pos=n-1;pos>=0;pos--){
            if (abs(nums[left])<abs(nums[right])){
                ans[pos]=nums[right]*nums[right];
                right--;
            }
            else{
                ans[pos]=nums[left]*nums[left];
                left++;
            }
        }
        return ans;

        
    }
};