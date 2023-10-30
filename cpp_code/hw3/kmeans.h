#pragma once
#include <vector>
#include "data.h"

using namespace std;

class cluster{
    uint8_t most_frequent_class;

    public:
    vector<double>* centroid; //Store centroid information
    vector<data*>* cluster_points; // List of data points in cluster
    
    cluster(data* initial_point); // Constructor. Sets the initial point as the centroid

    void add_to_cluster(data* point); // Add a data point to the cluster
    void set_most_frequent_class(); // Set the most frequent label among data points
    void update_centroid(); //Recalculate the centroid of a cluster based on the data points in a cluster

    uint8_t get_most_frequent_class(void);
};

class kmeans{
    private:    
    int k; // Number of clusters
    vector<cluster*>* clusters;
    vector<data*>* train_data;
    vector<data*>* test_data;
    vector<data*>* valid_data;

    
    public:
    void set_training_data(std::vector<data *> *vect);
    void set_test_data(std::vector<data *> *vect);
    void set_validation_data(std::vector<data *> *vect);

    kmeans(int num_cluster);
    void init_clusters(); // Initialize clusters
    double distance(vector<double>* centroid, data* point);
    void train(void); // Perform the k-means clustering on the training data 
                        // and update centroids of clusters
    double validate(void); // Calculate the percentage of data points 
                            // in the validation set that are correctly clustered 
                            // based on the most frequent class label within each cluster
};
