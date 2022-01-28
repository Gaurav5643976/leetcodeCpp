class WordDictionary {
public:
    class node{
      public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    node* trie;
    WordDictionary() {
        trie=new node;
    }
    
    void addWord(string word) {
        int n=word.size();
        node* it=trie;
        for(int i=0;i<n;i++){
            if(it->next[word[i]-'a']==NULL){
                it->next[word[i]-'a']=new node;
            }
            it=it->next[word[i]-'a'];
        }
        it->end=true;
    }
    
    bool search(string word) {
        return search(word.c_str(), trie);
    }
private:
    //TrieNode* root = new TrieNode();
    
    bool search(const char* word, node* n) {
        for (int i = 0; word[i] && n; i++) {
            if (word[i] != '.') {
                n = n -> next[word[i] - 'a'];
            } else {
                node* tmp = n;
                for (int j = 0; j < 26; j++) {
                    n = tmp -> next[j];
                    if (search(word + i + 1, n)) {
                        return true;
                    }
                }
            }
        }
        return n && n -> end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */