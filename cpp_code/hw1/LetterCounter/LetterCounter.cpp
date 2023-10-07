#include "LetterCounter.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <ctype.h>

// YOUR CODE HERE
using namespace std;
LetterCounter::LetterCounter(){}
/*
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
*/

int LetterCounter::GetWordCount(void){
    // to count the words in the text
    int Wcount = 0;
    istringstream iss(text);
    string word;
    while(iss >> word){
        Wcount++;
    }
    wordCount = Wcount;
    return wordCount;
}

int LetterCounter::GetCharacterCount(void){
    int Ccount = 0;
    istringstream iss(text);
    string word;
    while(iss >> word){
        // to count the characters in the text
        for(char ch : word){
            if(ch != '.' && ch != ','){
                Ccount++;
            }
            else {
                break;
            }
        }
    }
    charCount = Ccount;
    return charCount;
}

int LetterCounter::GetMaxWordCount(void){
    istringstream iss(text);
    string word;
    while(iss >> word){
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
        //cout << inputWord << endl; //for debugging

        if(wordCountMap.find(inputWord)!=wordCountMap.end()){
            wordCountMap[inputWord] += 1;
            //cout << wordCountMap[inputWord] << inputWord <<endl; //for debugging
        }
        else{
            wordCountMap.insert({inputWord,1});
        }
    }

    /*
    //for debugging
    for(const auto& pair : wordCountMap){
        cout << pair.first << "\t" << pair.second << endl;
    }
    */

    // to find the count of the most frequent word
    int maxCount = 0;
    int maxWordSize = 0;
    for(const auto& pair : wordCountMap){
        if(pair.second > maxCount){
            maxCount = pair.second;
        }
        // to find the longest word
        if(pair.first.size() > maxWordSize){
            maxWordSize = pair.first.size();
            longestWord = pair.first;
        }
    }
    maxWordCount = maxCount;
   
    return maxWordCount;
}

void LetterCounter::PrintLongestWord(void){
    cout << longestWord << endl;
}

void LetterCounter::PrintDistribution(void){
    istringstream iss(text);
    string word;
    while(iss >> word){
    // to make a map that maps 'char->count'
        for(char ch : word){
            if(ch!=','&& ch!='.'){
                ch = tolower(ch);
                if(charCountMap.count(ch)!=0){
                    charCountMap[ch]++;
                }
                else{
                    charCountMap.insert({ch,1});
                }
            }
            else{
                break;
            }
        }
    }

    /*
    //for debugging
    for(const auto& pair : charCountMap){
        cout << pair.first << "\t" << pair.second << endl;
    }
    */

    // drawing the distribution
    char ch;
    for(int i = 'a'; i<='z';i++){
        ch = i;

        //cout << ch ; //for debugging

        if(charCountMap.count(ch)!=0){
            cout << ch << ": " ;
            for(int j = 0; j < charCountMap[ch]; j++){
                cout << '*';
            }
        cout << endl;
        }
    }
}

void LetterCounter::InputText(const string& aText){
    text = aText;
    //cout << text << endl; // for debugging
}

