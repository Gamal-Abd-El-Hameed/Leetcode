class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (auto & child : children) {
            child = nullptr;
        }
        isEndOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return search(word, 0, root);
    }
private:
    bool search(const string &word, int wordIndex, TrieNode* node) {
        if (wordIndex == word.length())
            return node->isEndOfWord;
        char currentChar = word[wordIndex];
        if (currentChar == '.') {
            return any_of(node->children, node->children + 26, [&](TrieNode* child) {
                return child && search(word, wordIndex + 1, child);
            });
        }
        int childIndex = currentChar - 'a';
        return node->children[childIndex] && search(word, wordIndex + 1, node->children[childIndex]);
    }
};