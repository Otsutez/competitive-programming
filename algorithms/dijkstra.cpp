/*
Graph representation: adjacency list
Finding minimum vertex: use priority queue
*/
#include <map>
#include <list>
#include <utility>
#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;

class Graph {
    map<int, list<pair<int, int>>> adj_list;

    public:
        void add_edge(int u, int v, int wt) {
            adj_list[u].push_back({v, wt});
            adj_list[v].push_back({u, wt});
        }

        void print_graph() {
            for (auto const &p : adj_list) {
                cout << "Vertex " << p.first << " have edge to\n";
                for (auto d: p.second) {
                    cout << d.first << " weight: " << d.second << "\n";
                }
            }
        }

        void dijkstra(int start) {
            int n = adj_list.size();
            vector<int> distance (n, numeric_limits<int>::max());
            distance[start] = 0;
            vector<bool> visited (n, false);
            vector<int> prev (n);

            int count = n;
            while (count != 0) {
                // Get unvisited vertex with least distance
                int min = numeric_limits<int>::max();
                int u;
                for (int i = 0; i < n; i++) {
                    if (distance[i] < min && !visited[i]) {
                        min = distance[i];
                        u = i;
                    }
                }
                visited[u] = true;

                for (auto pair : adj_list[u]) {
                    int temp = distance[u] + pair.second;
                    if (temp < distance[pair.first]) {
                        distance[pair.first] = temp;
                        prev[pair.first] = u;
                    }
                }
                count--;
            }

            cout << "The shortest distance from u to\n";
            for (int i = 0; i < n; i++) {
                cout << i << ": " << distance[i] << "\n";
                stack<int> s;
                int curr = i;
                while (prev[curr] != start) {
                    s.push(curr);
                    curr = prev[curr];
                }
                cout << i;
                while (!s.empty()) {
                    cout << " -> " << s.top();
                    s.pop();
                }
                cout << "\n";
            }
        }
};

int main() {
    Graph g;
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 100);
    g.print_graph();
    g.dijkstra(0);
}
