#include <iostream>
#include <vector>
using namespace std;

void storeByValue(vector<int> aVec){
    vector<int> lVec = aVec;

    cout << "aVec: " << &aVec << ", " << &aVec.front() << " -- " << &aVec.back() << endl;
    cout << "lVec: " << &lVec << ", " << &lVec.front() << " -- " << &lVec.back() << endl;
}

void storeByLRef(vector<int>& aVec){
    vector<int> lVec = aVec;

    cout << "aVec: " << &aVec << ", " << &aVec.front() << " -- " << &aVec.back() << endl;
    cout << "lVec: " << &lVec << ", " << &lVec.front() << " -- " << &lVec.back() << endl;
}

void storeByRRef(vector<int>&& aVec){
    cout << "aVec before move: " << &aVec << ", " << &aVec.front() << " -- " << &aVec.back() << endl;

    vector<int> lVec = move(aVec); 
    // argument로 move(sVec)이 들어올지라도 구현단계에서 move(aVec)을 안해주면 move가 일어나지 않음!!!

    cout << "aVec after move: " << &aVec << ", " << &aVec.front() << " -- " << &aVec.back() << endl;
    cout << "lVec: " << &lVec << ", " << &lVec.front() << " -- " << &lVec.back() << endl;
}

int main(void){
    vector<int> sVec = {1,2,3,4,5};
    cout << "sVec at the beginning: " << &sVec << ", " << &sVec.front() << " -- " << &sVec.back() << endl;
    cout << "\n[Store By Value]\n";
    storeByValue(sVec);
    cout << "\n[Store By LRef]\n";
    storeByLRef(sVec);
    cout << "\n[Store By RRef]\n";
    storeByRRef(move(sVec));
    cout << "\nsVec at the end: " << &sVec << ", " << &sVec.front() << " -- " << &sVec.back() << endl;

    return 0;
}