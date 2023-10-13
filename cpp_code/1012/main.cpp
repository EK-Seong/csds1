#include "data_handler.h"
#include "data.h"
#include <iostream>

int main(){
    data_handler* dh = new data_handler;
    dh->read_feature_vector("./train-images-idx3-ubyte");
    dh->read_feature_labels("./train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();
}