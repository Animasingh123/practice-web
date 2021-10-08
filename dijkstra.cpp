#include <bits/stdc++.h>
using namespace std;
int minDistInd(vector<int>&dist,vector<bool>&vis)
{
    int minInd;
    int minDist=INT_MAX;
    for(int i=0;i<dist.size();++i)
    {
        if(!vis[i] && minDist>dist[i])
        {
            minDist=dist[i];
            minInd=i;
        }
    }
    return minInd;
}
void printSol(vector<int>&dist)
{
    cout<<"vertex distance from source"<<endl;
    for(int i=0;i<dist.size();++i)
    {
        cout<<i<<" \t\t"<<dist[i]<<endl;
    }
}
void dijkstra(vector<vector<int>>&graph,int src)
{
    int n=graph.size();
    vector<bool>vis(n,0);
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0 ; i < n-1 ; ++i)
    {
        int ind = minDistInd(dist,vis);
        vis[ind]=true;
        for(int v=0 ; v < n ; ++v)
        {
           if(!vis[v] && graph[ind][v]!=0 && dist[ind]!=INT_MAX)
           {
               dist[v]=min(dist[v],dist[ind]+graph[ind][v]);
           }
        }
    }
    printSol(dist);
}
int main()
{
    vector<vector<int>>graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
    return 0;
}