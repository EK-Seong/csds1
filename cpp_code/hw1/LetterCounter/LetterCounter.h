#pragma once
#include <string>
#include <unordered_map>

// YOUR CODE HERE
using namespace std;
class LetterCounter{
    public:
    int GetWordCount(void); // the number of words
    int GetCharacterCount(void); // the number of characters
    int GetMaxWordCount(void); // the count number of the most frequent word
    void PrintLongestWord(void);
    void PrintDistribution(void);
    void InputText(const string& aText);

    private:
    string text;
    int wordCount;
    int charCount;
    int maxWordCount;
    string longestWord;
    unordered_map<string, int> wordCountMap;
    unordered_map<char, int> charCountMap; 

    public:
    LetterCounter(const string& text);
    LetterCounter();
};