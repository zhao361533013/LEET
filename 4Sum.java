18. 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (nums == null || nums.length < 4){
            return result;
        }
        Arrays.sort (nums);
        int len = nums.length;
        for (int i = 0; i < len - 3 ; i++){
            if (i!=0&& nums [i]== nums[i-1] )
                continue;
           for (int j = i+1; j < len-2; j++){
               if (j!= i+1 && nums [j] == nums [j-1])
                   continue;
               int l = j+1; int r = len-1;
                while (l<r){
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target){
                        l++;
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target){
                        r--;
                    }
                    else {
                        List<Integer> temp = new ArrayList<Integer>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[l]);
                        temp.add(nums[r]);
                        result.add(temp);
                       
                        l++;
                        r--;
                         while (l<r && nums[r] == nums[r+1] ){
                            r--;
                        }
                        while (l< r &&nums[l] == nums[l-1]){
                            l++;
                        }
                    }
                }
           } 
        }
        return result;
    }
}
