16. 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
class Solution {
    public int threeSumClosest(int[] nums, int target) {
       int min = Integer.MAX_VALUE;
        int result = 0;
        if (nums == null || nums.length < 3 ){
            return 0;
        }
        Arrays.sort(nums);
        
        for (int i = 0;i< nums.length; i++){
            int j = i +1;
            int k = nums.length-1;
            while (j<k){
                int sum = nums[j] + nums[k] + nums[i];
                int diff = Math.abs(sum - target);
                
                if (diff == 0) return sum;
                if (diff < min){
                    min = diff;
                    result = sum;
                }
                if (sum< target){
                    j++;
                }
                else if (sum > target){
                    k--;
                }
            }
        }
     return result;
    }
}

// 3sum 问题的变种 第一次做的有点麻烦 维护两个指针 设立一个最大值。
