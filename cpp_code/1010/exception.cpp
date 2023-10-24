#include <iostream>
#include <exception>

using namespace std;

int main(){
    try{
        int size;
        int* myArray;

        cin >> size;
        myArray = new int[size];

        cout << "A new array with size " << size << " is created\n";
    }
    catch(const exception& e){
        cerr<< "Standard exception: " << e.what() << endl;
    }
    return 0;
}