#pragma once
#include <vector>
#include <string>

// your code
using namespace std;
class Stats{
    public:
    Stats();
    Stats(const string& inputString);
    double Avg(void);
    int MaxMinDiff(void);
    double Var(void);
    double Median(void);

    void PrintNums(void);

    private:
    vector<double> nums;
    double mean;
    double median;
    void selectionSort(vector<double>& arr);
};