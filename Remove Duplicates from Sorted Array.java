Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
class Solution {
    public int removeDuplicates(int[] nums) {
    if (nums == null){
        return 0;
    }
    int j = 1;
    int i = 1;
        while (i< nums.length){
            if (nums[i] ==nums[i-1]){
                i++;
            }
            else {
                nums[j] = nums[i];
                i++;
                j++;
                
            }
        }
        return j;
    }
}
