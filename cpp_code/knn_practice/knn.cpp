#include "knn.h"
#include "data_handler.h"
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

knn::knn(){}
knn::knn(int val){
    k = val;
}
knn::~knn(){}

void knn::set_train_data(vector<data*>* vect){
    train_data = vect;
}
void knn::set_test_data(vector<data*>* vect){
    test_data = vect;
}
void knn::set_valid_data(vector<data*>* vect){
    valid_data = vect;
}
void knn::set_k(int val){
    k = val;
}

double knn::distance(data* query_point, data* input){
    double dist = 0.0;
    for(int p = 0; p<query_point->get_feature_vector_size();p++){
        dist += pow(query_point->get_feature_vector()->at(p) - input->get_feature_vector()->at(p),2);
    }
    dist = sqrt(dist);
    return dist;
}
void knn::find_knearest(data* query_point){
    neighbors = new vector<data*>;
    double min = numeric_limits<double>::max();
    double prev_min = numeric_limits<double>::lowest();
    int index = 0;

    for(int i=0;i<k;i++){
        for(int j=0; j<train_data->size(); j++){
            train_data->at(j)->set_distance(knn::distance(query_point,train_data->at(j)));
        }
        for(int j=0; j<train_data->size(); j++){
            if(train_data->at(j)->get_distance() < min && train_data->at(j)->get_distance() > prev_min){
                min = train_data->at(j)->get_distance();
                index = j;
            }
        }
        neighbors->push_back(train_data->at(index));
        prev_min = min;
        min = numeric_limits<double>::max();
        index = 0;
    }
}
int knn::find_freq_class(void){
    map<uint8_t,int> class_freq;

    for(int i=0; i<k; i++){
        if(class_freq.find(neighbors->at(i)->get_label())==class_freq.end()){
            class_freq[neighbors->at(i)->get_label()] = int(1);
        }
        else{
            class_freq[neighbors->at(i)->get_label()]++;
        }
    }

    int most_freq = 0;
    int label_nearest;

    for(auto nn : class_freq){
        if(nn.second>most_freq){
            most_freq = nn.second;
            label_nearest = nn.first;
        }
    }
    delete neighbors;
    return label_nearest;
}

double knn::valid_performance(void){
    double rate_correct = 0.0;
    int count_correct = 0;

    for(data* query_point : *valid_data){
        find_knearest(query_point);
        if(find_freq_class() == query_point->get_label()){
            count_correct++;
        }
    }
    rate_correct = static_cast<double>(count_correct) / static_cast<double>(valid_data->size());
    
    cout << "Validation performance for K=" << k << " : " << rate_correct << endl;
    
    return rate_correct;
}
double knn::test_performance(void){
    double rate_correct = 0.0;
    int count_correct = 0;

    for(data* query_point : *test_data){
        find_knearest(query_point);
        if(find_freq_class() == query_point->get_label()){
            count_correct++;
        }
    }
    rate_correct = static_cast<double>(count_correct) / static_cast<double>(test_data->size());
    
    cout << "Test performance for K=" << k << " : " << rate_correct << endl;
    
    return rate_correct;
}