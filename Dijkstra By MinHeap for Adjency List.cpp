#include<bits/stdc++.h>
using namespace std;
#define pll pair<int,int>
vector<int>dis;
vector<bool>vis;
void dijkstra(vector<pll>adj[],int nodes,int s){
    dis.assign(nodes+1,INT_MAX);
    vis.assign(nodes+1,false);
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({0,s});
    dis[s]=0;
 
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u]==true)
            continue;
        vis[u]=true;
        for(int i=0;i<adj[u].size();i++){
            int w=adj[u][i].first;
            int v=adj[u][i].second;
            if(vis[v]==false){
                if(dis[u]!=INT_MAX&&dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
    }
}
int minCostPath(int g_nodes, vector<int>g_from,vector<int>g_to, vector<int>g_weight,int x, int y){
    vector<pll>adj[g_nodes+1];
    int u,v,w;
    for(int i=0;i<g_from.size();i++){
        u=g_from[i];
        v=g_to[i];
        w=g_weight[i];
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int sum=0;
    dijkstra(adj,g_nodes,1);
    sum+=dis[x];
    dijkstra(adj,g_nodes,x);
    sum+=dis[y];
    dijkstra(adj,g_nodes,y);
    sum+=dis[g_nodes];
    return sum;
}