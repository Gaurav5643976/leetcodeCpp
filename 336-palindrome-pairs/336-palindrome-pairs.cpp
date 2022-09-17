class TrieNode {
public:
    int idx;
    vector<int> indices;
    TrieNode* children[26];
    TrieNode() : idx(-1) {
        memset(children, NULL, sizeof(children));
    }
};
//https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            add(words[i], i);
        }
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            search(words[i], i, pairs);
        }
        return pairs;
    }
private:
    TrieNode* root = new TrieNode();
    
    void add(string word, int i) {
        TrieNode* node = root;
        for (int j = word.size() - 1; j >= 0; j--) {
            if (isPalindrome(word, 0, j)) {
                node -> indices.push_back(i);
            }
            if (!node -> children[word[j] - 'a']) {
                node -> children[word[j] - 'a'] = new TrieNode();
            }
            node = node -> children[word[j] - 'a'];
        }
        node -> idx = i;
        node -> indices.push_back(i);
    }
    
    void search(string &word, int i, vector<vector<int>>& pairs) {
        TrieNode* node = root;
        int n = word.size();
        for (int j = 0; j < n && node; j++) {
            if (node -> idx >= 0 && node -> idx != i && isPalindrome(word, j, n - 1)) {
                pairs.push_back({i, node -> idx});
            }
            node = node -> children[word[j] - 'a'];
        }
        if (node) {
            for (int idx : node -> indices) {
                if (i != idx) {
                    pairs.push_back({i, idx});
                }
            }
        }
    }
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};