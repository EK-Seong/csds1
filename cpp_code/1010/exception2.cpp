#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

double computeAverage(const vector<int>& nums){
    int sum = 0;
    for (const auto& num : nums){
        sum += num;
    }
    return static_cast<double>(sum)/static_cast<double>(nums.size());
}

int main(){
    vector<int> nums;
    ifstream inputFile ("input.txt");

    if(!inputFile.is_open()){
        cerr << "Failed to open inpu file!" << endl;
        return 1;
    }

    try {
        string line;
        while(getline(inputFile,line)){
            int num = stoi(line);

            nums.push_back(num);
        }

        double avg = computeAverage(nums);
        cout << "Average of numbers in input file: " << avg << endl;
    }

    catch(const exception& e){
        cerr << "Invalid input file: " << e.what() << endl;
        return 1;
    }

    return 0;
}
