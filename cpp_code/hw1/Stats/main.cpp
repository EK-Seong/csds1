#include "Stats.h"
#include <iostream>

using namespace std;

int main(void){
    string input_str = "5 2 1 4 7 8";
    Stats myStats = Stats(input_str);

    cout << "---------------------" << endl;
    cout << "Nums Input: "; myStats.PrintNums();
    cout << "AVG:          " << myStats.Avg() << endl;
    cout << "Max_Min_Diff: " << myStats.MaxMinDiff() << endl;
    cout << "VAR:          " << myStats.Var() << endl;
    cout << "Median:       " << myStats.Median() << endl;
    cout << "Nums After Execution: "; myStats.PrintNums();
    cout << "---------------------" << endl;

    return 0;
}