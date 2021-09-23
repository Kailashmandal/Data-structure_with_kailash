#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Dfs
{
    public:
    void DFS(int node ,vector<int> &vis,vector<int>adj[],vector<int>&dfs){
        dfs.push_back(node);
        vis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                DFS(it,vis,adj,dfs);
            }
        }
    }
    vector<int> DfsofGraph(int v,vector<int> adj[]){
        vector<int>dfs;
        vector<int> vis(v+1,0);

        for(int i=1;i<=v;i++){
            if(!vis[i]){
                DFS(i,vis,adj,dfs);
            }
        }
        return dfs;
    }
    
};



int main(int argc, char const *argv[])
{
   int n,m;
   cout<<"enter the number of nodes and edges";
   cin>>n>>m;
    Dfs g;
    cout<<"enter the edges combination";
   vector<int> adj[m+1];
   for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;
       adj[u][v]=1;
       adj[v][u]=1;
   }

   vector<int> v=g.DfsofGraph(n,adj);
   for(auto i:v)
   cout<<i<<" ";
    return 0;
}
