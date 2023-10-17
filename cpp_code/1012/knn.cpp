#include "knn.h"
#include <cmath>
#include <limits>
#include <iostream>
#include <cstdint>
#include <map>


    knn::knn(){}
    knn::~knn(){}

knn::knn(int Kvalue){
    k = Kvalue;
}

void knn::set_training_data(vector<data*>* aVector){
    training_data = aVector;
}

void knn::set_test_data(vector<data*>* aVector){
    test_data = aVector;
}

void knn::set_validation_data(vector<data*>* aVector){
    validation_data = aVector;
}

void knn::set_k(int Kvalue){
    k = Kvalue;
}



double knn::calculate_distance(data* query_point, data* input){
    double dist = 0.0;
    for(int i = 0;i<query_point->get_feature_vector_size();i++){
        dist += pow(query_point->get_feature_vector()->at(i)-input->get_feature_vector()->at(i),2);
    }
    dist = sqrt(dist);
    return dist;
}

void knn::find_knearest(data* query_point){
    neighbors = new vector<data*>;
    double min = numeric_limits<double>::max();
    double previous_min = min;
    int index = 0;
    for(int i=0;i<k;i++){
        if(i==0){
            for(int j=0;j<training_data->size();j++){
                double dist = calculate_distance(query_point,training_data->at(j));
                training_data->at(j)->set_distance(dist);
            
                if(dist<min){
                    min=dist;
                    index = j;
                }
            }
        
        neighbors->push_back(training_data->at(index));
        previous_min = min;
        min = numeric_limits<double>::max();
        }
        else{
            for(int j=0;j<training_data->size();j++){
                double dist = training_data->at(j)->get_distance();
                if(dist>previous_min && dist < min){
                    min = dist;
                    index = j;
                }
            }
            neighbors->push_back(training_data->at(index));
            previous_min = min;
            min = numeric_limits<double>::max();
        }
    }
}

int knn::find_freq_class(void){
    map<uint8_t,int> class_freq;
    for(int i=0;i<neighbors->size();i++){
        if(class_freq.find(neighbors->at(i)->get_label())==class_freq.end()){
            class_freq[neighbors->at(i)->get_label()] = 1;
        }
        else{
            class_freq[neighbors->at(i)->get_label()]++;
        }
    }
    int best = 0;
    int max = 0;
    for(auto kv: class_freq){
        if(kv.second>max){
            max = kv.second;
            best = kv.first;
        }
    }
    delete neighbors;
    return best;

}

double knn::validate_performance(void){
    double current_performance = 0;
    int count = 0;
    int data_index = 0;
    for(data* query_point : *validation_data){
        find_knearest(query_point);
        int prediction = find_freq_class();
        if(prediction == query_point->get_label()){
            count++;
        }
    }
    current_performance = ((double)count * 100.0) / (double)validation_data->size();

    cout << "Validation performances for K = " << k << " : " << current_performance << endl;

    return current_performance;
}
double knn::test_performance(void){
    double current_performance = 0;
    int count = 0;
    int data_index = 0;
    for(data* query_point : *test_data){
        find_knearest(query_point);
        int prediction = find_freq_class();
        if(prediction == query_point->get_label()){
            count++;
        }
    }
    current_performance = ((double)count * 100.0) / (double)test_data->size();
    return current_performance;
}