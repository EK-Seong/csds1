#include "data_handler.h"
#include "data.h"
#include "knn.h"
#include <iostream>

int main(){
    data_handler* dh = new data_handler;
    dh->read_feature_vector("./train-images-idx3-ubyte");
    dh->read_feature_labels("./train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();

    knn* knearest = new knn();
    knearest->set_training_data(dh->get_training_data());
    knearest->set_test_data(dh->get_test_data());
    knearest->set_validation_data(dh->get_validation_data());
    double performance = 0;
    double best_performance = 0;
    int best_k;

    for(int i =1;i<=4;i++){
        if(i==1){
            knearest->set_k(i);
            performance = knearest->validate_performance();
            best_performance = performance;
        }
        else{
            knearest->set_k(i);
            performance = knearest->validate_performance();
            if(performance>best_performance){
                best_performance = performance;
                best_k = i;
                cout <<"for loop best_k: " << best_k << endl;
            }
        }
    }
    knearest->set_k(best_k);
    knearest->test_performance();
    cout << "best_k: "<<best_k<<endl;

    return 0;
}