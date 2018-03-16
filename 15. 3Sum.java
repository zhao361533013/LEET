15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
    List <List<Integer>> ret = new ArrayList<List<Integer>>();
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null || nums.length < 3 ) return ret;
        
        Arrays.sort(nums);
        
        int len = nums.length;
        for (int i =0 ; i < len - 2 ; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            find (nums, i+1, len-1, nums[i]);
        }
        return ret;
    }
    
    public void find (int []nums, int begin , int end , int target){
        int m = 0-target;
        while (begin< end){
 
      if (nums[begin] + nums[end]== m){
                List<Integer> n = new ArrayList<Integer>();
                n.add(target);
                n.add(nums[begin]);
                n.add(nums[end]);
                ret.add(n);
                while (begin < end && nums[begin] == nums[begin+1]) begin++;
                while (begin < end && nums[end] == nums[end-1]) end--;
                begin++;
                end--;
            }
        else if (nums[begin] + nums[end] > m){
                end -- ;
            }
        else{
                begin++;
            }
        }
        
    }
}
// 先对数组进行排序 （反正排序函数不用我写）， 然后再依次遍历每一个数， 对他的相反数设置为 target 然后维护两个指针，
遍历整个数组找出所有符合条件的组合
