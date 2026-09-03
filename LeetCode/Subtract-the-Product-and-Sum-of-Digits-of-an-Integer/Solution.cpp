1class Solution {
2public:
3    int subtractProductAndSum(int n) {
4        int prod=1;
5        int sum=0;
6        while(n!=0){
7            int digit=n%10; //remainder
8            prod=prod*digit;
9            sum=sum+digit;
10            n=n/10;
11
12        }
13        int ans=prod-sum;
14        return ans;
15        
16    }
17};