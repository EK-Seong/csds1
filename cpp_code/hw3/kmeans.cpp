#include "kmeans.h"
#include "data_handler.h"
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

void kmeans::set_training_data(std::vector<data *> *vect){
    train_data = vect;
}
void kmeans::set_test_data(std::vector<data *> *vect){
    test_data = vect;
}
void kmeans::set_validation_data(std::vector<data *> *vect){
    valid_data = vect;
}


/*---------------------------------------------------------*/


cluster::cluster(data* initial_point){
    centroid = new vector<double>;
    cluster_points = new vector<data*>;
    for(int p=0;p<initial_point->get_feature_vector_size();p++){
        centroid->push_back(static_cast<double>(initial_point->get_feature_vector()->at(p)));
    }
}
void cluster::add_to_cluster(data* point){
    cluster_points->push_back(point);
}
void cluster::set_most_frequent_class(void){
    map<uint8_t,int> map_class_to_count;

    for(int i=0; i<cluster_points->size(); i++){
        if(map_class_to_count.find(cluster_points->at(i)->get_label())==map_class_to_count.end()){
            map_class_to_count.insert({cluster_points->at(i)->get_label(),1});
        }
        else{
            map_class_to_count[cluster_points->at(i)->get_label()]++;
        }
    }
        /*// for debugging
    for(auto pair : map_class_to_count){
        cout << "Class: " << static_cast<int>(pair.first) << " has count of " << pair.second << endl;
    }*/

    int most_freq = 0;
    uint8_t label_nearest = 0;

    for(auto nn : map_class_to_count){
        if(nn.second>most_freq){
            most_freq = nn.second;
            label_nearest = nn.first;
        }
    }
    most_frequent_class = label_nearest;

    //debugging
    /*cout << "Most frequent class : " << static_cast<int>(most_frequent_class)
    << " which has " << map_class_to_count[most_frequent_class] << " data points" << endl;*/
}

void cluster::update_centroid(){
    // average of all the points in the cluster
    for(int p=0; p<centroid->size(); p++){
        double sum = 0.0;
        for(data* element : *cluster_points){
            sum += static_cast<double>(element->get_feature_vector()->at(p));
        }
        centroid->at(p) = sum / static_cast<double>(cluster_points->size());
    }
}

uint8_t cluster::get_most_frequent_class(void){
    return most_frequent_class;
}


/* ---------------------------------------------------------------------------------- */


kmeans::kmeans(int num_cluster){
    k = num_cluster;
    clusters = new vector<cluster*>(k);
}
void kmeans::init_clusters(){
    // Initialize clusters with 0~(k-1)-th data points as initial centroids.
    for(int i=0; i<k; i++){
        clusters->at(i) = new cluster(train_data->at(i));
    }
}
double kmeans::distance(vector<double>* centroid, data* point){
    double dist = 0.0;
    for(int p = 0; p<centroid->size();p++){
        dist += pow(centroid->at(p) - static_cast<double>(point->get_feature_vector()->at(p)),2);
    }
    dist = sqrt(dist);
    return dist;
}
void kmeans::train(void){
/* Perform the k-means clustering on the training data 
 and update centroids of clusters */
    // 1. initialize clusters
    init_clusters();
    // 2. Add data points to their nearest centroid
    for(data* point : *train_data){
        int nearest;
        double min_dist = numeric_limits<double>::max();
        double dist = 0.0;
        for(int i=0; i<k; i++){
            dist = distance(clusters->at(i)->centroid, point);
            if(min_dist>dist){
                min_dist = dist;
                nearest = i;
            }
        }
        // Add to the nearest cluster
        clusters->at(nearest)->add_to_cluster(point);
    }

    /*//debugging
    for(cluster* c : *clusters){
        cout << c->cluster_points->size() << "-";
    }
    cout << endl;*/


    // 3. update centroids of clusters
    for(cluster* c : *clusters){
        /*// need to print previous centroids for debugging
        cout << "Previous centroid : ";
        for(int i =0; i<c->centroid->size();i++){
            cout << c->centroid->at(i) << " ";
        }
        cout << endl;*/

        c->update_centroid();

        /*// need to print new centroids for debugging
        cout << "New centroid : ";
        for(int i =0; i<c->centroid->size();i++){
            cout << c->centroid->at(i) << " ";
        }
        cout << endl;*/
    }
    /*// 4. Update cluster data points
        // first delete all the previous points
    for(cluster* c : *clusters){
        delete c->cluster_points;
        c->cluster_points = new vector<data*>;
    }

        //for debugging
        //cout << "Successfully deleted data points in clusters" << endl;

        // next add new data points in the training data to
        // the nearest centroid
    for(data* point : *train_data){
        int nearest;
        double min_dist = numeric_limits<double>::max();
        double dist = 0.0;
        
        for(int i=0; i<k; i++){
            dist = distance(clusters->at(i)->centroid, point);
            if(min_dist>dist){
                min_dist = dist;
                nearest = i;
            }
        }
        // Add to the nearest cluster
        
        clusters->at(nearest)->add_to_cluster(point);
    }

    //for debugging  여기까지는 실행됨
    //cout << "Successfully updated clusters" << endl;

        //debugging
    cout << "size of each cluster : ";
    for(cluster* c : *clusters){
        cout << c->cluster_points->size() << "-";
    }
    cout << endl;

        //
    cout << "Train data size : " << train_data->size() << endl;*/


    // 5. Set the most frequent class(label) for each cluster.
    for(cluster* c : *clusters){
        //for debug
        //cout << endl;
        c->set_most_frequent_class();
    }
}

double kmeans::validate(void){
/* Calculate the percentage of data points 
 in the validation set that are correctly clustered 
 based on the most frequent class label within each cluster */

    // match validation data points with their nearest centroids

    double correct = 0;

    for(data* point : *valid_data){
        int nearest;
        double min_dist = numeric_limits<double>::max();
        double dist = 0.0;
        for(int i=0; i<k; i++){
            dist = distance(clusters->at(i)->centroid, point);
            if(min_dist>dist){
                min_dist = dist;
                nearest = i;
            }
        }
        // compare the labels of the validation data point and its centroid.
        if(point->get_label()==clusters->at(nearest)->get_most_frequent_class()){
            correct++;
        }
    }

    /*// for dubugging
    for(int i=0; i<k; i++){
        cout << "The most frequent class in the " << i << "-th cluster: " << static_cast<int>(clusters->at(i)->get_most_frequent_class()) << endl;
    }*/

    double performance = 0.0;
    performance = static_cast<double>(correct) / static_cast<double>(valid_data->size());
    return performance*100;
}