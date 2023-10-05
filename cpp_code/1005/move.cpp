#include <iostream>
#include <vector>
using namespace std;

void storeByValue(vector<int> aVec);

void storeByLRef(vector<int>& aVec);

void storeByRRef(vector<int>&& aVec);