# Line-by-Line Explanation
**1. Function Definition**
<br>
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
```
Defines a class Solution with a public method majorityElement.
Takes a reference to a vector of integers nums.
Returns an integer: the majority element.<br>
<br>
**2. Initialize Helper Variables**
<br>
```
      int maxcount=0;
      int count=0;
      int majority=0;;
```
maxcount → stores the highest frequency of any element found so far.
count → temporary counter for the current element.
majority → stores the current candidate for majority element.<br>
<br>
**3. Create Visited Array**
<br>
```
      vector<bool> visited(nums.size(), false);
```
vector<bool> → vector of true/false values.
nums.size() → same size as the input array.
false → all elements initially unvisited.
Purpose: ensures that once we count an element, we don’t count it again in future iterations.
Example at start:
nums    = [2, 3, 2]
visited = [false, false, false]<br>
<br>
**4. Outer Loop**
<br>
```
      for(int i=0; i<nums.size(); i++){
```
Iterates through each element in nums.
i is the index of the current element we are checking.<br>
<br>
**5. Skip Already Counted Elements**
<br>
```
        if (visited[i]) continue;
```
If visited[i] is true, we skip this iteration.
continue; → moves to the next i in the outer loop.
Prevents recounting numbers we have already processed.<br>
<br>
**6. Inner Loop**
<br>
```
        for(int j=0; j<nums.size(); j++){
```
Compares nums[i] with every element in the array.
j is the index of the element being compared to nums[i].<br>
<br>
**7. Count Occurrences and Mark Visited**
<br>
```
        if(nums[i]==nums[j]){
            count++;
            visited[j] = true;
        }
```
If nums[i] == nums[j] → we found another occurrence.
count++ → increment the frequency of nums[i].
visited[j] = true → mark this index as counted, so it won’t be counted again in future iterations.
Why mark visited[j] instead of visited[i]?
Because there might be multiple occurrences of the same number later in the array.
Marking visited[j] ensures that all duplicates are counted once, and skipped in future outer-loop iterations.<br>
<br>
**8. Update Majority Element**
<br>
 ```
     if (count>maxcount){
        maxcount=count;
        majority = nums[i];
      }
```
After counting all occurrences of nums[i]:
If count is greater than maxcount, update maxcount.
Set majority = nums[i] → this element currently has the highest frequency.<br>
<br>
**9. Reset Count for Next Iteration**
<br>
```
      count=0;
```
Reset count to 0 for the next i.<br>
<br>
**10. Return Result**
<br>
 ```
     return majority; 
    }
};
```
After checking all elements, return majority.
This is the element that appeared most frequently in the array.<br>
<br>
**Dry Run Example**<br>
<br>
nums = [2, 3, 2]<br>
visited = [false, false, false]<br>
maxcount = 0<br>
majority = 0<br>
<br>
**Step 1:** i = 0, nums[0] = 2<br>
visited[0] = false → proceed<br>
Inner loop:<br>
j = 0 → nums[0]==nums[0] → count=1, visited[0]=true → visited=[true,false,false]<br>
j = 1 → nums[0]!=nums[1] → nothing<br>
j = 2 → nums[0]==nums[2] → count=2, visited[2]=true → visited=[true,false,true]<br>
count=2 > maxcount=0 → update maxcount=2, majority=2<br>
Reset count=0<br>
<br>
**Step 2:** i = 1, nums[1] = 3<br>
visited[1] = false → proceed<br>
Inner loop:<br>
j=0 → visited[0]=true → skip<br>
j=1 → nums[1]==nums[1] → count=1, visited[1]=true → visited=[true,true,true]<br>
j=2 → visited[2]=true → skip<br>
count=1 → not greater than maxcount=2 → majority stays 2<br>
Reset count=0<br>
<br>
**Step 3:** i = 2, nums[2] = 2<br>
visited[2] = true → skip outer loop<br>
Final Result:<br>
majority = 2<br>
<br>
✅ Works perfectly!<br>

**Key Insights About visited:**<br>

```visited[i]``` is true → we already counted this element, skip it.<br>
```visited[j]``` = true → mark duplicates as counted while looping.<br>

Ensures each element is counted exactly once, mimicking your original nested loop but avoiding repeated work.
