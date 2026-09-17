1class Solution(object):
2    def mySqrt(self, x):
3        """
4        :type x: int
5        :rtype: int
6        """
7
8        if x < 2:
9            return x
10
11        low = 1
12        high = x // 2
13        ans = 0
14
15        while low <= high:
16            mid = (low + high) // 2
17
18            if mid * mid <= x:
19                ans = mid
20                low = mid + 1
21            else:
22                high = mid - 1
23
24        return ans
25
26        