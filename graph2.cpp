#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    /*
    when we have high numbers of nodes in graph then we can use adjection list
    */
cout<<"enter the number of vertex and no of edges";
   int n,m;
   cin>>n>>m;

   vector<int> adj[n+1];

   for(int i=0;i<m;i++){
       int u,v;
       cin>>u>>v;
  
       adj[u].push_back(v); // it will mark the uth index of we  an vector 
       adj[v].push_back(u);  // it will mark the vth index of adj array with vector
   }
    return 0;
}
