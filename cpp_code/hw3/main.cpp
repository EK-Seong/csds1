#include "kmeans.h"
#include <iostream>
#include "data_handler.h"

int main(){
    data_handler* dh = new data_handler;
    dh->read_feature_vector("./train-images-idx3-ubyte");
    dh->read_feature_labels("./train-labels-idx1-ubyte");
    dh->split_data();
    double performance =0.0;
    int k= 30;

    kmeans* km = new kmeans(k);
    km->set_training_data(dh->get_training_data());
    km->set_test_data(dh->get_test_data());
    km->set_validation_data(dh->get_validation_data());
    km->init_clusters();   
    km->train();
    performance = km->validate();
    std::cout<<"Current Performance: " <<performance <<std::endl;
} 
