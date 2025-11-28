#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u])
        if(!vis[v]){ 
            dfs(v);
        }
}

int main(){
    int V, E;
    cin >> V >> E;

    adj = vector<vector<int>>(V);
    vis = vector<int>(V, 0);

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    for(int u = 0; u < V; u++){
        if(!vis[u]){
            count++;
            dfs(u);
        }
    }
    cout << "Number of components are: " << count;
}