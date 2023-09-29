#include <iostream>
#include <list>
#include <vector>

using namespace std;

class undi_graph{
    int vNum; // The Number of vertices
    vector<vector<int>> neighbors;
    
    public:
    undi_graph(const int& num, const vector<vector<int>>& edges);
    void visitAction(const int& v);

    void bfs(void);
};

/* Construct a graph using vertices and edges */
undi_graph::undi_graph(const int& num, const vector<vector<int>>& edges)
            :neighbors(num,vector<int>(0)){
    vNum = num;

    for(int i=0;i<edges.size();i++){
        /* If edges[i] is (u,v), add v to the u's neighbor list and
                                 add u to the v's neighbor list */
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
}

/* Print the vertex on the screen */
void undi_graph::visitAction(const int& v){
    cout << v << " ";
}


/* visit all vertices in the graph with breadth-first search*/
void undi_graph::bfs(void){
    vector<bool> visited(vNum, false);

}

int main(void){
    // Graph construction using 10 vertices
    int myVNum = 10;
    vector<vector<int>> myEdges{
        {0,1}, {1,4}, {1,5}, {2,3}, {4,6}, 
        {5,6}, {5,7}, {6,9}, {7,8}
    };
    undi_graph myGraph(myVNum, myEdges);

    cout << "[BFS] ";
    myGraph.bfs();
    cout << endl;

    cout << "[DFS preorder] ";
    myGraph.dfs(0);
    cout << endl;

    cout << "[DFS postorder] ";
    myGraph.dfs(1);
    cout << endl;

    return 0;
}
