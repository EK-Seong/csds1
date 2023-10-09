#include "Stats.h"
#include <string>
#include <sstream>
#include <iostream>

// your code
using namespace std;

Stats::Stats(){};
Stats::Stats(const string& inputString){
    double aNum;
    istringstream iss(inputString);
    while(iss >> aNum){
        nums.push_back(aNum);
    }
}

double Stats::Avg(void){
    double sum = 0;
    for(const double& n : nums){
        sum += n;
    }
    double avg = sum/nums.size();
    mean = avg;
    return mean;
}

int Stats::MaxMinDiff(void){
    double max = 0;
    for(const double& n : nums){
        if(n>max){
            max = n;
        }
    }
    double min = 10001;
    for(const double& n : nums){
        if(n<min){
            min = n;
        }
    }
    int diff = max - min;
    return diff; 
}

double Stats::Var(void){
    double sum = 0;
    for(const double& n : nums){
        sum += ((n - mean) * (n - mean));
    }
    double var = sum/nums.size();
    return var;
}

double Stats::Median(void){
    vector<double> copynums;
    for(const double& n : nums){
        copynums.push_back(n);
    }
    selectionSort(copynums);
    
    /*
    //for debugging
    for(const double& n : copynums){
        cout << n << " ";
    }
    cout << endl;
    */

    double med;
    int indexMed;
    if (nums.size()%2 == 1){
        indexMed = nums.size()/2;
        med = copynums[indexMed];
    }
    else{
        indexMed = nums.size()/2;
        //cout << indexMed << endl;
        med = (copynums[indexMed-1]+copynums[indexMed])/2;
    }
    median = med;
    return med;
}

void Stats::selectionSort(vector<double>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}




// PrintNums - Do not change
void Stats::PrintNums(){
    for (int i: nums){
        cout << i << ' ';
    }
    cout << endl;
}