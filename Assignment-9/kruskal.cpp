#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, wt;
};

// Simple find function (slow)
int findParent(int node, vector<int> &parent) {
    while (parent[node] != node)
        node = parent[node];
    return node;
}

// Simple union function
void unionSet(int a, int b, vector<int> &parent) {
    int pa = findParent(a, parent);
    int pb = findParent(b, parent);
    if (pa != pb)
        parent[pb] = pa;   // attach one root to another
}

int main() {
    int n, m;
    cin >> n >> m;   // n = nodes, m = edges

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    // Step 1: sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.wt < b.wt;
    });

    // Parent initialization
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int totalWeight = 0;

    cout << "Edges in MST:" << endl;

    // Step 2: pick edges one by one
    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);

        if (pu != pv) {                // no cycle
            cout << e.u << " - " << e.v << " (" << e.wt << ")\n";
            totalWeight += e.wt;
            unionSet(pu, pv, parent);  // merge components
        }
    }

    cout << "Total MST Weight = " << totalWeight << endl;
}
