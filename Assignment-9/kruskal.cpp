#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n){
        p.resize(n);
        r.assign(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find_set(int u){
        if(p[u]==u) return u;
        return p[u]=find_set(p[u]);
    }
    void link_set(int u,int v){
        if(r[u] > r[v]) p[v]=u;
        else if(r[u] < r[v]) p[u]=v;
        else{
            p[v]=u;
            r[u]++;
        }
    }
    void union_set(int u,int v){
        u = find_set(u);
        v = find_set(v);
        if(u!=v) link_set(u,v);
    }
};

int main(){
    int V,E;
    cin >> V >> E;
    vector<array<int,3>> edges;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    DSU d(V);
    int cost=0;
    for(auto &e: edges){
        int w=e[0], u=e[1], v=e[2];
        if(d.find_set(u) != d.find_set(v)){
            cost += w;
            d.union_set(u,v);
        }
    }
    cout << cost;
}
