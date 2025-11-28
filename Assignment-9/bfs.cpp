#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<vector<int>> adj = {
        {1},         // 0 -> 1
        {2, 3},     // 1 -> 2, 3
        {4},        // 2 -> 4
        {5},        // 3 -> 5
        {},         // 4
        {}          // 5
    };

    vector<bool> vis(6, 0);
    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}