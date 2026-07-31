class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        for(int j=1;j<size;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};