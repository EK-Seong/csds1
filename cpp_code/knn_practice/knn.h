#pragma once
#include "data.h"
#include <vector>

using namespace std;

class knn{
    int k;
    vector<data*>* neighbors;
    vector<data*>* train_data;
    vector<data*>* test_data;
    vector<data*>* valid_data;

    public:
    knn();
    knn(int k);
    ~knn();

    void set_train_data(vector<data*>* vect);
    void set_test_data(vector<data*>* vect);
    void set_valid_data(vector<data*>* vect);

    void set_k(int k);
    double distance(data* query_point, data* input);
    void find_knearest(data* query_point);
    int find_freq_class(void);

    double valid_performance(void);
    double test_performance(void);
};