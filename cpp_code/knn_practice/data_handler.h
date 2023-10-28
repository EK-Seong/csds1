#pragma once
#include "data.h"
#include <map>
#include <string>

using namespace std;

class data_handler{
    private:
    vector<data*>* data_array;
    vector<data*>* train_data;
    vector<data*>* test_data;
    vector<data*>* valid_data;
    int num_classes;
    int feature_vector_size;
    map<uint8_t,int> class_map;

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALID_SET_PERCENT = 0.05;

    public:
    data_handler();
    ~data_handler();

    void read_feature_vector(string path);
    void read_feature_label(string path);
    void split_data(void);
    void count_classes(void);

    uint32_t convert_to_little_endian(const unsigned char* bvtes);

    int get_classes_counts(void);
    vector<data*>* get_train_data(void);
    vector<data*>* get_test_data(void);
    vector<data*>* get_valid_data(void);
};