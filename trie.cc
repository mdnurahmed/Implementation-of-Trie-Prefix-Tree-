
class WordDictionary {
   public:
    bool found;
    struct node {
        //endmark true means a word ends in this node 
        bool endmark;
        unordered_map<char, node*> next;
        node() {
            endmark = false;
        }
    };
    node* root;
    void insert(string& str) {
        node* cur = root;
        for (int i = 0; i < str.size(); i++) {
            if (cur->next.find(str[i]) == cur->next.end()) {
                cur->next[str[i]] = new node();
            }
            cur = cur->next[str[i]];
        }
        cur->endmark = true;
    }
    void dfs_search(string& str, int pos, node* cur) {
        if (pos == str.size()) {  //final check
            if (cur->endmark) found = true;
            return;
        }
        if (str[pos] == '.') {  //can choose any node
            for (auto it = cur->next.begin(); it != cur->next.end(); it++) {
                if (found) return;  //no need to check anymore
                dfs_search(str, pos + 1, it->second);
            }
        } else {
            if (cur->next.find(str[pos]) == cur->next.end()) {
                return;
            }
            dfs_search(str, pos + 1, cur->next[str[pos]]);
        }
    }
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        found = false;
        dfs_search(word, 0, root);
        return found;
    }
};