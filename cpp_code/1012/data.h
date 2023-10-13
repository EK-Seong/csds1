#pragma once
#include <vector>
#include "cstdint"

using namespace std;

class data{
    private:
    vector<uint8_t>* feature_vector;
    uint8_t label;

    public:
    data();
    ~data();
    void set_feature_vector(vector<uint8_t>*);
    void append_to_feature_vector(uint8_t);
    void set_label(uint8_t);

    vector<uint8_t>* get_feature_vector(void);
    int get_feature_vector_size(void);
    uint8_t get_label(void);
    //uint8_t get_enumerated_label(void);
};