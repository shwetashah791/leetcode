class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {}
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isEndOfWord;

        char ch = word[index];
        if (ch == '.') {
            for (auto& child : node->children) {
                if (searchHelper(word, index + 1, child.second)) return true;
            }
        } else {
            if (node->children.count(ch)) {
                return searchHelper(word, index + 1, node->children[ch]);
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */