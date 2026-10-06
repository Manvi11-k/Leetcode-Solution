1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4
5        // Count frequency of each task
6        vector<int> freq(26, 0);
7
8        for (char task : tasks) {
9            freq[task - 'A']++;
10        }
11
12        // Find maximum frequency
13        int maxFreq = 0;
14
15        for (int i = 0; i < 26; i++) {
16            maxFreq = max(maxFreq, freq[i]);
17        }
18
19        // Count how many tasks have maximum frequency
20        int maxCount = 0;
21
22        for (int i = 0; i < 26; i++) {
23            if (freq[i] == maxFreq) {
24                maxCount++;
25            }
26        }
27
28        // Calculate minimum intervals
29        int answer = (maxFreq - 1) * (n + 1) + maxCount;
30
31        // If there are enough different tasks,
32        // no idle time is needed
33        return max((int)tasks.size(), answer);
34    }
35};