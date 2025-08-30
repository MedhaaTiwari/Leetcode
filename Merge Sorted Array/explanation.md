Line by line expalnation of code:
The Overall Plan:

The strategy here is to first take all the numbers from the second list (nums2) and just stick them onto the end of the first list (nums1). Once all the numbers are in nums1, the code then sorts the entire list from scratch.

Code Breakdown

C++
int a=0;
This line declares an integer variable a and sets it to 0. This variable will be used as a counter to help us grab the numbers from nums2 in order.

C++
for(int i=m; i<(m+n); i++){
    nums1[i]=nums2[a];
    a++;
}
This is the first main part of the code. It's a loop that goes through the empty slots in nums1 (starting at index m, which is where the zeroes begin). In each step of the loop, it copies a number from nums2 into nums1. The a++ makes sure it moves to the next number in nums2 with each step. By the time this loop finishes, nums1 will contain all the numbers from both original arrays, but they'll be in a jumbled, unsorted order.

C++
for (int j = 0; j <(m+n-1); j++){
    for(int i=0; i<(m+n-1); i++)
    {
        if (nums1[i]>nums1[i+1]){
            int temp = nums1[i];
            nums1[i]= nums1[i+1];
            nums1[i+1]= temp;
        }
    }
}
This is the second part of the code, and it's where the sorting happens. It's a nested loop, which is what makes this a bubble sort.

The outer loop (for (int j = 0; ... )) makes sure we go through the list enough times to get everything sorted. For a list of k items, it needs to go through about k times.

The inner loop (for(int i=0; ... )) does the actual work. It steps through the list from beginning to end.

if (nums1[i]>nums1[i+1]): This is the core logic. It checks if the current number is bigger than the next one. If it is, they are in the wrong order.

int temp = nums1[i]; ...: If the numbers are out of order, these lines swap their positions. It's like putting a number in a temporary holding spot so you can move the other number into its place and then move the first number into the new empty spot.

The whole process is called a bubble sort because, with each pass of the inner loop, the largest unsorted number "bubbles up" to its correct position at the end of the list. By repeating this process with the outer loop, the entire array eventually gets sorted.
