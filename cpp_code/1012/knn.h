#pragma once
#include "data.h"

using namespace std;

class knn{
    int k;
    vector<data*>* neighbors;
    vector<data*>* training_data;
    vector<data*>* test_data;
    vector<data*>* validation_data;

    public:
    knn(int Kvalue);
    knn();
    ~knn();

    void set_training_data(vector<data*>*);
    void set_test_data(vector<data*>*);
    void set_validation_data(vector<data*>*);
    void set_k(int Kvalue);

    double calculate_distance(data* query_point, data* input);
    void find_knearest(data* query_point);
    int find_freq_class(void);
    
    double validate_performance(void);
    double test_performance(void);
};