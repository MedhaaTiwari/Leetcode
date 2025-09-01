class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int maxcount=0;
      int count=0;
      int majority=0;;
      vector<bool> visited(nums.size(), false);
      for(int i=0; i<nums.size(); i++){
        if (visited[i]) continue; 
        for(int j=0; j<nums.size(); j++){
        if(nums[i]==nums[j]){
            count++;
            visited[j] = true;
        }
      }
      if (count>maxcount){
        maxcount=count;
        majority = nums[i];
    
      }  
      count=0;
      } 
      return majority; 
    }
};
