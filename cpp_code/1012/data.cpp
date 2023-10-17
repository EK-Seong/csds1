#include "data.h"

using namespace std;

data::data(){
    feature_vector = new vector<uint8_t>;
}

data::~data(){
    delete feature_vector;
}

void data::set_feature_vector(vector<uint8_t>* aVector){
    feature_vector = aVector;
}

void data::append_to_feature_vector(uint8_t val){
    feature_vector->push_back(val);
}

void data::set_label(uint8_t aLabel){
    label = aLabel;
}

vector<uint8_t>* data::get_feature_vector(void){
    return feature_vector;
}
int data::get_feature_vector_size(void){
    return feature_vector->size();
}

uint8_t data::get_label(void){
    return label;
}

//uint8_t data::get_enumerated_label(void)

void data::set_distance(double aDist){
    distance = aDist;
}

double data::get_distance(void){
    return distance;
}