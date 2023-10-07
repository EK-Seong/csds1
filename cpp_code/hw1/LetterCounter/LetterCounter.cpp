#include "LetterCounter.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

// YOUR CODE HERE
using namespace std;
LetterCounter::LetterCounter(){}
LetterCounter::LetterCounter(const string& text){

    // to count the words in the text
    int Wcount = 0;
    int Ccount = 0;
    cout << text << endl;
    istringstream iss(text);
    string word;
    while(iss >> word){
        Wcount++;

        // to count the characters in the text
        for(char ch : word){
            if(ch != '.' && ch != ','){
                Ccount++;
            }
            else {
                break;
            }
        }

        // to make a map for 'word -> countNum' mapping
        string inputWord = "";
        for(char ch : word){
            if(ch!=',' && ch!='.'){
                inputWord += ch;
            }
            else{
                break;
            }
        }
        wordCountMap[inputWord]++;

        // to make a map that maps 'char->count'
        for(char ch : word){
            if(ch!=','&& ch!='.'){
                charCountMap[ch]++;
            }
            else{
                break;
            }
        }
    }
    wordCount = Wcount;
    charCount = Ccount;
    
    // to find the count of the most frequent word
    int maxCount = 0;
    for(const auto& pair : wordCountMap){
        if(pair.second > maxCount){
            maxCount = pair.second;
        }
    }
    maxWordCount = maxCount;

    // to find the longest word
    int wordSize = 0;
    for(const auto& pair : wordCountMap){
        if(pair.second > wordSize){
            wordSize = pair.second;
            longestWord = pair.first;
        }
    }
}

int LetterCounter::GetWordCount(void){
    return wordCount;
}

int LetterCounter::GetCharacterCount(void){
    return charCount;
}

int LetterCounter::GetMaxWordCount(void){
    return maxWordCount;
}

void LetterCounter::PrintLongestWord(void){
    cout << longestWord << endl;
}

void LetterCounter::PrintDistribution(void){
    char ch;
    for(int i = 'a'; i<='Z';i++){
        ch = i;
        if(charCountMap[ch]){
            for(int j = 0; j < charCountMap[ch]; j++){
                cout << '*';
            }
        cout << endl;
        }
    }
}

void LetterCounter::InputText(const string& aText){
    text = aText;
    cout << text << endl;
}

