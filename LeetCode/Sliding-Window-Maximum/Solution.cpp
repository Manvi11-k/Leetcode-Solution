1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        priority_queue<pair<int,int>>pq;
5        vector<int>ans;
6        for(int i=0;i<nums.size();i++){
7            pq.push({nums[i],i});
8            if(i>=(k-1)){
9                while(pq.top().second<=i-k){
10                    pq.pop();
11                }
12                ans.push_back(pq.top().first);
13            }
14        }
15        return ans;
16        
17    }
18};