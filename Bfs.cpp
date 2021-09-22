#include<bits/stdc++.h>
using namespace std;

class Bfs
{
private:
    /* data */
public:

vector<int> bfsOfGraph(int v ,vector<int> adj[]){
    vector<int> bfs; // declare the bfs traversal vector 
    vector<int> vis(v+1,0); // create a visited vector of size v+1

    for(int i=1;i<=v;i++){
        if(!vis[i]){ // if ith node is not visited
            queue<int>q;  // create  a queue
            q.push(i); // push the i into queue
            vis[i]=1; // mark the ith index in visited vector as visited

            while (!q.empty())// while q is not empty
            {
                int node=q.front(); // make a variable and store front element of queue
                q.pop(); // pop the front 
                bfs.push_back(node); // push variable in the vector

                for(auto it : adj[node]){  // for ith index adjecent vector treversal 
                    if(!vis[it]){   // if vadj vector in not visited
                        q.push(it); // then push it into the queue
                        vis[it]=1; // and mark it as visited
                    }
                }
                /* code */
            }
            
        }
    }
    return bfs; // returnb the bfs vector 
}
   
};



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
 Bfs f;
   vector<int> v=f.bfsOfGraph(n,adj);

   for(auto i: v){
       cout<<i<<" ";
   }
    return 0;
}
