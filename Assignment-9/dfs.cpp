#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj = {
    {1},         // 0 -> 1
    {2, 3},     // 1 -> 2, 3
    {4},        // 2 -> 4
    {5},        // 3 -> 5
    {},         // 4
    {}          // 5
};

vector<int> vis(6, 0);

void dfs(int u) {
    vis[u] = 0;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    dfs(0);
}
