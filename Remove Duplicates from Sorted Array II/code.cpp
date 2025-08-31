 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    for(int i=nums.size()-3; i>=0; i--){
            if (nums[i]==nums[i+2])
            {
                 nums.erase(nums.begin() + (i+2));
            }
    }  
    return nums.size();
    }
    
};
