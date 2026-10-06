1class Solution {
2public:
3
4    // Find maximum subsequence of length k
5    vector<int> getMax(vector<int>& nums, int k) {
6
7        vector<int> st;
8        int remove = nums.size() - k;
9
10        for (int x : nums) {
11
12            while (!st.empty() && remove > 0 && st.back() < x) {
13                st.pop_back();
14                remove--;
15            }
16
17            st.push_back(x);
18        }
19
20        while (st.size() > k) {
21            st.pop_back();
22        }
23
24        return st;
25    }
26
27
28    // Merge two subsequences
29    vector<int> merge(vector<int>& a, vector<int>& b) {
30
31        vector<int> ans;
32
33        int i = 0;
34        int j = 0;
35
36        while (i < a.size() || j < b.size()) {
37
38            if (j == b.size() || 
39                (i < a.size() && a[i] > b[j])) {
40
41                ans.push_back(a[i]);
42                i++;
43
44            }
45            else if (i == a.size() || b[j] > a[i]) {
46
47                ans.push_back(b[j]);
48                j++;
49
50            }
51            else {
52
53                // digits are equal
54                if (greaterPart(a, i, b, j)) {
55                    ans.push_back(a[i]);
56                    i++;
57                }
58                else {
59                    ans.push_back(b[j]);
60                    j++;
61                }
62            }
63        }
64
65        return ans;
66    }
67
68
69    // Compare remaining parts of two arrays
70    bool greaterPart(vector<int>& a, int i,
71                     vector<int>& b, int j) {
72
73        while (i < a.size() && j < b.size()) {
74
75            if (a[i] > b[j])
76                return true;
77
78            if (a[i] < b[j])
79                return false;
80
81            i++;
82            j++;
83        }
84
85        return i != a.size();
86    }
87
88
89    // Compare two complete answers
90    bool greater(vector<int>& a, vector<int>& b) {
91
92        for (int i = 0; i < a.size(); i++) {
93
94            if (a[i] > b[i])
95                return true;
96
97            if (a[i] < b[i])
98                return false;
99        }
100
101        return false;
102    }
103
104
105    vector<int> maxNumber(vector<int>& nums1,
106                          vector<int>& nums2,
107                          int k) {
108
109        vector<int> answer;
110
111        int start = max(0, k - (int)nums2.size());
112        int end = min(k, (int)nums1.size());
113
114        for (int take1 = start; take1 <= end; take1++) {
115
116            int take2 = k - take1;
117
118            vector<int> a = getMax(nums1, take1);
119            vector<int> b = getMax(nums2, take2);
120
121            vector<int> current = merge(a, b);
122
123            if (answer.empty() || greater(current, answer)) {
124                answer = current;
125            }
126        }
127
128        return answer;
129    }
130};