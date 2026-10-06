1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4
5        unordered_map<char, char> mp1;
6        unordered_map<char, char> mp2;
7
8        for (int i = 0; i < s.length(); i++) {
9
10            char a = s[i];
11            char b = t[i];
12
13            if (mp1.count(a) && mp1[a] != b)
14                return false;
15
16            if (mp2.count(b) && mp2[b] != a)
17                return false;
18
19            mp1[a] = b;
20            mp2[b] = a;
21        }
22
23        return true;
24    }
25};