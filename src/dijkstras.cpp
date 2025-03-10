#include "dijkstras.h"

// G is a vector of edges

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    previous.assign(n, INF);
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});
    while (!minHeap.empty()) {
        int dist = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (Edge edge : G[u]) {
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    return distances;
}

// Returns a vector of ints

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (distances[destination] == INF)
        return path;
    for (int v = destination; v != -1; v = previous[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    return path;

}

void print_path(const vector<int>& v, int total) {
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    cout << endl;
    cout << total << endl;
}
