31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


class Solution {
    public void nextPermutation(int[] nums) {
       if (nums!=null && nums.length >1 ){
        int l = nums.length;
        int i = l-1;
        int temp = -1;
        while (temp == -1 && i > 0){
            if (nums[i]> nums[i-1]){
                temp = i-1;
            }
            i--;
        }
        if (temp!= -1){
         int temp2 = 1000000;
         int t3 = 0;
         for (int m = temp+1; m<=nums.length-1; m++){
             if (nums[m] > nums[temp]&& nums[m] < temp2){
                 temp2 = nums[m];
                 t3 = m;
             }
         }
           swap (nums, temp, t3);
           Arrays.sort(nums,temp+1,nums.length);
       }
           if (temp == -1){
               Arrays.sort(nums);
           }
       
    }
    }
    public void swap (int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
