1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        int m=n;
5        int mask =0;
6
7        if(n==0)
8        return 1;
9
10        while(m!=0){
11            mask=(mask << 1)| 1;
12            m=m>>1;
13        }
14        int ans = (~n) & mask;
15        return ans;
16        
17    }
18};