1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
4        
5        unordered_set<string> st(wordList.begin(), wordList.end());
6        queue<string> q;
7        
8        q.push(beginWord);
9        int level = 1;
10        
11        // endWord dictionary mein nahi hai
12        if (st.find(endWord) == st.end())
13            return 0;
14        
15        while (!q.empty()) {
16            
17            int size = q.size();
18            
19            while (size--) {
20                
21                string word = q.front();
22                q.pop();
23                
24                if (word == endWord)
25                    return level;
26                
27                // Har character ko change karo
28                for (int i = 0; i < word.length(); i++) {
29                    
30                    char original = word[i];
31                    
32                    for (char c = 'a'; c <= 'z'; c++) {
33                        
34                        word[i] = c;
35                        
36                        // Agar valid word hai
37                        if (st.find(word) != st.end()) {
38                            q.push(word);
39                            st.erase(word);  // visited
40                        }
41                    }
42                    
43                    word[i] = original;
44                }
45            }
46            
47            level++;
48        }
49        
50        return 0;
51    }
52};