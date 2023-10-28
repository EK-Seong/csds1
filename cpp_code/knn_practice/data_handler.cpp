#include "data_handler.h"
#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

data_handler::data_handler(){
    data_array = new vector<data*>;
    train_data = new vector<data*>;
    test_data = new vector<data*>;
    valid_data = new vector<data*>;
}
data_handler::~data_handler(){
    delete data_array;
    delete train_data;
    delete test_data;
    delete valid_data;
}

void data_handler::read_feature_vector(string path){
    uint32_t header[4];
    char buff[4];
    ifstream f(path,ios::binary);
    if(f.is_open()){
        for(int i=0;i<4;i++){
            f.read(buff,4);
            header[i] = convert_to_little_endian(reinterpret_cast<unsigned char*>(buff));
            cout << header[i] << "\n";
        }
        cout << "Done getting Input file header.\n";
        int image_size = header[2]*header[3];
        for(int i=0;i<header[1]*0.1;i++){
            data* d = new data();
            char element;
            for(int j=0;j<image_size;j++){
                if(f.read(&element,1)){
                    d->append_to_feature_vector(static_cast<uint8_t>(element));
                }
                else{
                    cout << "Error Reading from Input file.\n";
                    exit(1);
                }
            }
            data_array->push_back(d);
        }
        cout << "Successfully read and stored " << data_array->size() << " feature vectors.\n";
    }
    else{
        cout << "Could not find file.\n";
        exit(1);
    }
}
void data_handler::read_feature_label(string path){
    uint32_t header[2];
    char buff[4];
    ifstream f(path, ios::binary);
    if(f.is_open()){
        for(int i =0;i<2;i++){
            f.read(buff,4);
            header[i] = convert_to_little_endian(reinterpret_cast<unsigned char*>(buff));
            cout << header[i] << "\n";
        }
        cout << "Done getting Input file beader.\n";

        for(int i = 0; i < header[1]*0.1; i++){
            char element;
            if(f.read(&element,1)){
                data_array->at(i)->set_label(static_cast<uint8_t>(element));
            }
            else{
                cout << "Error Reading from Input file.\n";
                exit(1);
            }
        }
        cout << "Successfully read and stored " << data_array->size() << " labels.\n";
    }
    else{
        cout << "Could not find the file.\n";
        exit(1);
    }
}
void data_handler::split_data(void){
    int train_data_size = data_array->size()*TRAIN_SET_PERCENT;
    int test_data_size = data_array->size()*TEST_SET_PERCENT;
    int valid_data_size = data_array->size()*VALID_SET_PERCENT;

    vector<int> shuffleIdx(data_array->size());
    for(int i=0;i<data_array->size();i++){
        shuffleIdx[i] = i;
    }
    shuffle(shuffleIdx.begin(),shuffleIdx.end(),default_random_engine(1));

    for(int i=0;i<train_data_size;i++){
        train_data->push_back(data_array->at(shuffleIdx[i]));
    }
    for(int i=0;i<test_data_size;i++){
        test_data->push_back(data_array->at(shuffleIdx[i+train_data_size]));
    }
    for(int i=0; i<valid_data_size;i++){
        valid_data->push_back(data_array->at(shuffleIdx[i+train_data_size+test_data_size]));
    }
    cout << "training data size: " << train_data->size() << endl;
    cout << "test data size: " << test_data->size() << endl;
    cout << "validation data size: " << valid_data->size() << endl;
}
void data_handler::count_classes(void){
    int count = 0;
    cout << "array size: " << data_array->size() << endl;
    for(int i=0;i<data_array->size();i++){
        if(class_map.find(data_array->at(i)->get_label())==class_map.end()){
            class_map[data_array->at(i)->get_label()] = count;
            count++;
        }
    }
    num_classes = count;
    cout << "Successfully extracted " << num_classes << " unique classes.\n";
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes){
    return uint32_t((bytes[0] << 24)|
                    (bytes[1] << 16)|
                     (bytes[2] << 8)|
                     (bytes[3]));
}

int data_handler::get_classes_counts(void){
    return num_classes;
}
vector<data*>* data_handler::get_train_data(void){
    return train_data;
}
vector<data*>* data_handler::get_test_data(void){
    return test_data;
}
vector<data*>* data_handler::get_valid_data(void){
    return valid_data;
}