class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = buildTrie(words);
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                search(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (const string& word : words) {
            TrieNode* node = root;
for (char c : word) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            
            node->word = word;
        }
        
        return root;
    }
    
    void search(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '#' || node->children[board[i][j] - 'a'] == nullptr) {
            return;
        }
        
        char temp = board[i][j];
        TrieNode* next = node->children[temp - 'a'];
        
        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word = "";
        }
   board[i][j] = '#';
        
        search(board, i - 1, j, next, result);
        search(board, i + 1, j, next, result);
        search(board, i, j - 1, next, result);
        search(board, i, j + 1, next, result);
        
        board[i][j] = temp;
    }
};