#include "Disjoint.h"
void graphDSF(int node,vector<vector<int>> adj,vector<int> & vis){
    vis[node] = 1;
    for(int i =0;i<adj[node].size();i++){
        if(adj[node][i] == 1 && vis[i] == 0){
            graphDSF(i,adj,vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V) {
    vector<int> vis(V,0);
    int count = 0;
    for(int i =0;i<V;i++){
        if(vis[i] == 0){
            count++;
            graphDSF(i,adj,vis);
        }
    }
    return count;
}

// Using Disjoint Set
int numProvinces(vector<vector<int>> adj, int V) {
    Disjoint ds(V);
    for(int i =0;i<adj.size();i++){
        for(int j =0;j<adj[i].size();j++){
            if(adj[i][j] == 1)
                ds.unionByRank(i,j);
        }
    }
    set<int> ans;
    for(int i =0;i<V;i++)
        ans.insert(ds.findParent(i));
    return ans.size();
}