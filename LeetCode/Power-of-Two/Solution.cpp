1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        int ans=1;
5        for (int i=0;i<=30;i++){
6            if(ans==n){
7                return true;
8            }
9            if(ans< INT_MAX/2)
10            ans=ans*2;
11        }
12        return false ;
13        
14    }
15};