#include <iostream>
#include <string>
#include "LetterCounter.h"
using namespace std;

int main() {
  
  	char text[10000];
    cout << "Type a sentence and press *Enter*.\n";
    cin.getline(text, 10000, '\n');

    LetterCounter counter;
	counter.InputText(text);
	
	cout << "Word Count: " << counter.GetWordCount() << endl;
	cout << "Character Count: " << counter.GetCharacterCount() << endl;
	cout << "Maximum Number of Word Count: " << counter.GetMaxWordCount() << endl;
    cout << "The Longest Word is ";
    counter.PrintLongestWord();
 	cout << "The Letter Distribtion: " << endl;
    counter.PrintDistribution();
 	
 	return 0;
}
