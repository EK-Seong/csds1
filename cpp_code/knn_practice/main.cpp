#include "data_handler.h"
#include "knn.h"
#include <iostream>


int main(void){
    data_handler* dh = new data_handler;
    dh->read_feature_vector("./train-images-idx3-ubyte");
    dh->read_feature_label("./train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();

    knn* knearest = new knn();
    knearest->set_train_data(dh->get_train_data());
    knearest->set_valid_data(dh->get_valid_data());
    knearest->set_test_data(dh->get_test_data());

    double performance = 0;
    double best_performance = 0;
    int best_k = 0;

    for (int k=1; k<=4; k++){
        knearest->set_k(k);
        performance = knearest->valid_performance();
        if(performance > best_performance){
            best_performance = performance;
            best_k = k;
        }
    }


    cout << "best_k is : " << best_k << " , with the performance : " << best_performance << endl;
    knearest->set_k(best_k);
    performance = knearest->test_performance();

    return 0;
}