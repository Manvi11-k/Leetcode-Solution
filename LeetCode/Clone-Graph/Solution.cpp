1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    unordered_map<Node*, Node*> mp;
25
26    Node* cloneGraph(Node* node) {
27        
28        if (node == NULL)
29            return NULL;
30
31        // Already cloned
32        if (mp.count(node))
33            return mp[node];
34
35        // Create new node
36        Node* clone = new Node(node->val);
37
38        // Store it
39        mp[node] = clone;
40
41        // Clone all neighbors
42        for (Node* neighbor : node->neighbors) {
43            clone->neighbors.push_back(cloneGraph(neighbor));
44        }
45
46        return clone;
47    }
48};