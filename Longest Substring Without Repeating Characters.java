3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.




class Solution {
    public int lengthOfLongestSubstring(String s) {
        int temp = 0;
        if (s == null || s.length() == 0){
            return 0;
        }
        HashSet <Character> set = new HashSet<Character>();
        int max = 0;
        int walker = 0;
        int runner = 0;
        while (runner < s.length())
        {
            if (set.contains(s.charAt(runner))){
                if (max < runner - walker)
                {
                    max = runner - walker;
                }
                while (s.charAt(walker) != s.charAt(runner))
                {
                    set.remove(s.charAt(walker));
                    walker ++;
                }
                walker ++;
            }
            else 
            {
                set.add(s.charAt(runner));
            }
            runner ++;
        }
        max = Math.max(max,runner-walker);
        return max;
    }
}
// 思路就是维护一个窗口 使用一个哈希表来存储已出现的字符  如果左字符与右字符不相等，移动窗口
