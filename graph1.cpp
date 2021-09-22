#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
// for nodes of size n we can take size of (n+1)*(n+1) and mark every uth and vth cell that represent the edge
// BY adjcent matrix 
int n,m;
cin>>n>>m;

int adj[n+1][n+1];

// take the edge as input 
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u][v]=1; // marking cell of u,v 
    adj[v][u]=1;  // marking cell of v,u
}
    return 0;
}
