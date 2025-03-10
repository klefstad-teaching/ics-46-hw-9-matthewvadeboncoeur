#include "dijkstras.h"


int main() {
    Graph G;
    file_to_graph("src/small.txt", G);
    vector<int> distances;
    vector<int> prevs;
    distances = dijkstra_shortest_path(G, 0, prevs);
    vector<int> res;
    int dest = 3;
    res = extract_shortest_path(distances, prevs, dest);
    print_path(res, distances[dest]);
    return 0;
}