//
// Created by tanad on 11/9/2022.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#include "not_so_simple_graph.h"

int main()
{

    Graph* graph1 = new Graph();
    graph1->insertEdge(0, 1, 10);
    graph1->insertEdge(0, 5, 25);
    graph1->insertEdge(1, 2, 20);
    graph1->insertEdge(1, 4, 25);
    graph1->insertEdge(2, 3, 30);

    if (graph1->isEdge(1, 4)) {
        cout<< 1 << endl;
    }
    else {
        cout<< 0 << endl;
    }
    cout << graph1->sumEdge(1, 2) << endl;

    vector<int> weight = graph1->getWeight(0, 1);
    for (int i = 0; i < weight.size(); ++i) {
        cout << weight.at(i) << endl;
    }
    vector<int> adjacent = graph1->getAdjacent(0);
    for (int i = 0; i < adjacent.size(); ++i) {
        cout << adjacent.at(i) << endl;
    }


}