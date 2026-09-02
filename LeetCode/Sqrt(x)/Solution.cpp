1class Solution {
2public:
3    int mySqrt(int x) {
4        int l=1,h=x/2;
5        int mid,ans;
6        if(x<2)
7        return x;
8        while(l<=h){
9            mid=(l+h)/2;
10            if(mid<=x/mid){
11                ans=mid;
12                l=mid+1;
13            }
14            else{
15                h=mid-1;
16            }
17        }
18        return ans;
19        
20    }
21};