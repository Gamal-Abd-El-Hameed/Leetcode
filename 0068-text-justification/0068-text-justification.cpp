class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> curLine, res;
        int numOfWordsInLine = 0, lineCounter = 0;
        for (int wordsCounter = 0; wordsCounter < words.size(); wordsCounter++) {
            string word = words[wordsCounter], line;
            if (wordsCounter == words.size() - 1) {
                if (numOfWordsInLine > 0)
                    curLine.back() += ' ';
                curLine.push_back(word);
                for (const string& wordInLine:curLine)
                    line += wordInLine;
                while (line.length() < maxWidth)
                    line += ' ';
                res.push_back(line);
            }
            else {
                if (numOfWordsInLine > 0) {
                    curLine.back() += ' ';
                    lineCounter++;
                }
                curLine.push_back(word);
                numOfWordsInLine++;
                lineCounter += word.length();
                if (lineCounter + words[wordsCounter + 1].length() >= maxWidth) {
                    if (numOfWordsInLine == 1) {
                        while (word.length() < maxWidth)
                            word += ' ';
                        res.push_back(word);
                    }
                    else {
                        int totalExtraSpaces = maxWidth - lineCounter;
                        if (totalExtraSpaces > 0) {
                            int singleExtraSpaces = totalExtraSpaces / (numOfWordsInLine - 1);
                            for (int i = 0; i < numOfWordsInLine - 1; i++)
                                for (int j = 0; j < singleExtraSpaces; j++)
                                    curLine[i] += ' ';
                            int remainingExtraSpaces = totalExtraSpaces % (numOfWordsInLine - 1);
                            for (int i = 0; i < remainingExtraSpaces; i++)
                                curLine[i] += ' ';
                        }
                        for (const string& wordInLine:curLine)
                            line += wordInLine;
                        res.push_back(line);
                    }
                    curLine.clear();
                    numOfWordsInLine = 0, lineCounter = 0;
                }
            }
        }
        return res;
    }
};