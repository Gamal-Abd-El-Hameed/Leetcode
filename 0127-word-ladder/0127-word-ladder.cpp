class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            // If endWord is not in the wordList, there's no valid transformation sequence.
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int ladderLength = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            ladderLength++;
            
            for (int i = 0; i < levelSize; i++) {
                string currentWord = q.front();
                q.pop();
                
                for (int j = 0; j < currentWord.length(); j++) {
                    char originalChar = currentWord[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue; // Skip the same character.
                        
                        currentWord[j] = c; // Replace the character.
                        
                        if (currentWord == endWord) {
                            return ladderLength + 1; // Found the endWord, return the length.
                        }
                        
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            q.push(currentWord); // Add the transformed word to the queue.
                            wordSet.erase(currentWord); // Mark the word as visited.
                        }
                        
                        currentWord[j] = originalChar; // Restore the word for the next iteration.
                    }
                }
            }
        }
        
        return 0; // No transformation sequence found.
    }
};
