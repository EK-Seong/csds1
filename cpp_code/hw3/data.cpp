#include "data.h"

using namespace std;

data::data(){
    feature_vector = new vector<uint8_t>; //굳이?어차피 set_feature_vector에서 화살표를 바꾸잖아?
}
data::~data(){
    delete feature_vector;
}

void data::set_feature_vector(vector<uint8_t>* aVec){
    feature_vector = aVec;
}
vector<uint8_t>* data::get_feature_vector(void){
    return feature_vector;
}
void data::append_to_feature_vector(uint8_t val){
    feature_vector->push_back(val);
}
int data::get_feature_vector_size(void){
    return feature_vector->size();
}

void data::set_label(uint8_t aLabel){
    label = aLabel;
}
uint8_t data::get_label(void){
    return label;
}

double data::get_distance(void){
    return distance;
}
void data::set_distance(double aDist){
    distance = aDist;
}