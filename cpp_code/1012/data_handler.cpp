#include "data_handler.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

data_handler::data_handler(){
    data_array = new vector<data*>;
    training_data = new vector<data*>;
    test_data = new vector<data*>;
    validation_data = new vector<data*>;
}
data_handler::~data_handler(){
    delete data_array;
    delete training_data;
    delete test_data;
    delete validation_data;
};

void data_handler::read_feature_vector(string path){
    uint32_t header[4]; // | magic num | num images | rowsize | colsize |
    char buff[4];
    ifstream f(path, ios::binary);
    if(f.is_open()){
        for (int i = 0; i < 4; i++){
            f.read(buff,4);
            header[i] = convert_to_little_endian(reinterpret_cast<unsigned char*>(buff));
            cout << header[i] << endl;
        }
        cout << "Done getting Input file header." << endl;
        int image_size = header[2]*header[3];
        for(int i=0; i < header[1]*0.1; i++){
            data* d = new data();
            char element;
            for(int j=0;j< image_size;j++){
                if(f.read(&element,1)){
                    d->append_to_feature_vector(static_cast<uint8_t>(element));
                }
                else{
                    cout << "Error Reading from Input file." << endl;
                    exit(1); //???
                }
            }
            data_array->push_back(d);
        }
        cout << "Successfully read and strored " << data_array->size() << " feature vectors" << endl;
    }
    else{
        cout << "Could not find file." << endl;
        exit(1); //이게 뭐지?
    }
}

void data_handler::read_feature_labels(string path){
    uint32_t header[4]; // | magic num | num images |
    char buff[4];
    ifstream f(path, ios::binary);
    if(f.is_open()){
        for (int i = 0; i < 2; i++){
            f.read(buff,4);
            header[i] = convert_to_little_endian(reinterpret_cast<unsigned char*>(buff));
            cout << header[i] << endl;
        }
        cout << "Done getting Input file header." << endl;
        for(int i=0; i < header[1]*0.1; i++){
            data* d = new data();
            char element;
            if(f.read(&element,1)){
                data_array->at(i)->set_label(static_cast<uint8_t>(element));
            }
            else{
                cout << "Error Reading from Input file." << endl;
                exit(1); //???
            }
            data_array->push_back(d);
        }
        cout << "Successfully read and strored " << data_array->size() << " labels" << endl;
    }
    else{
        cout << "Could not find file." << endl;
        exit(1); //이게 뭐지?
    }
}
void data_handler::split_data(){
    int training_size = data_array->size()*TRAIN_SET_PERCENT;
    int test_size = data_array->size()*TEST_SET_PERCENT;
    int validataion_size = data_array->size()*VALIDATION_PERCENT;

    vector<int> shuffleIdx(data_array->size());
    for(int i=0;i<data_array->size();i++){
        shuffleIdx[i] = i;
    }
    shuffle(shuffleIdx.begin(),shuffleIdx.end(), default_random_engine(1));

    for(int i=0;i<data_array->size();i++){
        training_data->push_back(data_array->at(shuffleIdx[i]));
    }
    for(int i=0;i<test_size;i++){
        test_data->push_back(data_array->at(shuffleIdx[training_size+i]));
    }
    for(int i =0;i<validataion_size;i++){
        validation_data->push_back(data_array->at(shuffleIdx[training_size+test_size+i]));
    }
    cout << "training data size " << training_data->size() << endl;
    cout << "test data size " << test_data->size() << endl;
    cout << "validation data size " << validation_data->size() << endl;
}

void data_handler::count_classes(){
    num_classes;
}

uint32_t data_handler::convert_to_little_endian(const unsigned char* bytes){
    return(uint32_t)  ((bytes[0]<<24))|
                        (bytes[1]<<16)|
                         (bytes[2]<<8)|
                            (bytes[3]);
}

vector<data*>* data_handler::get_training_data(){
    return training_data;
}

vector<data*>* data_handler::get_test_data(){
    return test_data;
}

vector<data*>* data_handler::get_validation_data(){
    return validation_data;
}

