1class Solution(object):
2    def lengthOfLastWord(self, s):
3        """
4        :type s: str
5        :rtype: int
6        """
7        length = 0
8        i = len(s) - 1
9
10        # Skip spaces at the end
11        while i >= 0 and s[i] == ' ':
12            i -= 1
13
14        # Count the last word
15        while i >= 0 and s[i] != ' ':
16            length += 1
17            i -= 1
18
19        return length
20        