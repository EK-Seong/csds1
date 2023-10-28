#pragma once
#include <cstdint>
#include <vector>

using namespace std;

class data{
    vector<uint8_t>* feature_vector; // Data point 저장
    uint8_t label; //label 0~9 저장
    double dist;

    public:
    data();
    ~data();

    void set_feature_vector(vector<uint8_t>* aVec);
    vector<uint8_t>* get_feature_vector(void);
    void append_to_feature_vector(uint8_t);
    int get_feature_vector_size(void);
    
    void set_label(uint8_t aLabel);
    uint8_t get_label(void);

    double get_distance(void);
    void set_distance(double aDist);
};