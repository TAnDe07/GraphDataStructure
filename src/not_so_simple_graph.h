/*
    Not so simple Graph

    Write C++ code for implementing a Graph data structure that supports a directed graph with 
    self-loops and parallel edges. You are expected to implement the following methods and a main
    method is already built for you:

        void *insertEdge*(int from, int to, int weight);   // 1
        bool *isEdge*(int from, int to);                   // 2
        int *sumEdge*(int from, int to);                   // 3
        vector<int> *getWeight*(int from, int to);         // 4
        vector<int> *getAdjacent*(int vertex);             // 5


    Sample Input:
        7    
        1 0 0 10  
        1 0 1 20 
        1 0 2 30
        2 0 0  
        3 0 2 
        4 0 1
        5 0
    
    Sample Output:
        1  
        30
        20 
        0 1 2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Graph
{
   private:
      // TODO: Graph structure that supports parallel edges and self-loops
      map<int,  vector<pair<int, float>>> graph;

    public:
      void insertEdge(int from, int to, int weight);  
      bool isEdge(int from, int to);  
      int sumEdge(int from, int to); 
      std::vector<int> getWeight(int from, int to); 
      std::vector<int> getAdjacent(int vertex);
      bool SearchKey(int from, map<int, vector<pair<int, float>>> graph);
};

//Helper Function
bool Graph::SearchKey(int to, map<int, vector<pair<int, float>>> graph) {
    map<int,  vector<pair<int, float>>> :: iterator itr;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        //if the key exists, add pair (to, rank) to key
        if (itr->first == to) {
            return true;
        }
    }
    return false;
}

void Graph::insertEdge(int from, int to, int weight) 
{
   /*
        TODO: insertEdge() adds a new edge between the from 
        and to vertex.
   */

    bool exists = false;
    vector<pair<int, float>> temp;
    //if empty insert first element in graph
    if (graph.empty()) {
        temp.emplace_back(to, weight);
        graph[from] = temp;
        if (from != to) {
            graph[to] = {};
        }
    }
    //if graph is not empty
    else if (!graph.empty()) {
        map<int,  vector<pair<int, float>>> :: iterator itr;
        //look for the key (from) in graph,
        for (itr = graph.begin(); itr != graph.end(); itr++) {
            //if the key exists, add pair (to, rank) to key
            if (itr->first == from) {
                exists = true;
                itr->second.emplace_back(to,  weight);
                //if to (key) does not exist in graph, create empty element
                if (!SearchKey(to, graph)) {
                    graph[to] = {};
                }
                break;
            }
        }
        //if the key does not exist, add a new key
        if (!exists) {
            temp.emplace_back(to,  weight);
            graph[from] = temp;
            //if to (key) does not exist in graph, create empty element
            if (!SearchKey(to, graph)) {
                graph[to] = {};
            }
        }
    }

}
        
bool Graph::isEdge(int from, int to) 
{
    /*
        TODO: isEdge() returns a boolean indicating true 
        if there is an edge between the from and to vertex
    */
    map<int,  vector<pair<int, float>>> :: iterator itr;
    vector<pair<int, float>> temp;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        if (itr->first == from) {
            temp = itr->second;
            break;
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        if (temp.at(i).first == to) {
            return true;
        }
    }
    return false;
}

int Graph::sumEdge(int from, int to)
{
    /*
        TODO: sumEdge() returns the sum of weights of all edges 
        connecting the from and to vertex. Returns 0 if no edges 
        connect the two vertices.
    */
    map<int,  vector<pair<int, float>>> :: iterator itr;
    int sum = 0;
    vector<pair<int, float>> temp;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        if (itr->first == from) {
            temp = itr->second;
            break;
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        if (temp.at(i).first == to) {
            sum += temp.at(i).second;
        }
    }

    return sum;
}

std::vector<int> Graph::getWeight(int from, int to)
{
    /*
        TODO: getWeight() returns a sorted vector containing all 
        weights of the edges connecting the from and to vertex
    */
    map<int,  vector<pair<int, float>>> :: iterator itr;
    int sum = 0;
    vector<pair<int, float>> temp;
    vector<int> weights = {};
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        if (itr->first == from) {
            temp = itr->second;
            break;
        }
    }

    for (int i = 0; i < temp.size(); ++i) {
        if (temp.at(i).first == to) {
            weights.push_back(temp.at(i).second);
        }
    }
    sort(weights.begin(), weights.end());

    return weights;
}

std::vector<int> Graph::getAdjacent(int vertex) 
{
    /*
        TODO: getAdjacent() returns a sorted vector of all vertices
        that are connected to a vertex
    */
    map<int,  vector<pair<int, float>>> :: iterator itr;
    int sum = 0;
    vector<pair<int, float>> temp;
    for (itr = graph.begin(); itr != graph.end(); itr++) {
        if (itr->first == vertex) {
            temp = itr->second;
           break;
        }
    }
    vector<int> adjacent = {};
    for (int i = 0; i < temp.size(); ++i) {
        adjacent.push_back(temp.at(i).first);
    }
    sort(adjacent.begin(), adjacent.end());

    return adjacent;
}
