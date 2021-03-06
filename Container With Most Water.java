11. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.


class Solution {
    public int maxArea(int[] height) {
        int temp = 0 ;int result = 0;
        int i = 0; int j = height.length -1;
        if (height == null || height.length < 2){
            return 0;
        } 
        while (j>i){
            temp = (j-i)*Math.min(height[j],height[i]);
            result = Math.max (result, temp);
            if (height[j]>height[i]){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
}
