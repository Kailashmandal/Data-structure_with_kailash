#include<bits/stdc++.h>
using namespace std;
// k larger element using max heap or priority queue
int main(int argc, char const *argv[])
{
    int v[]={2,10,3, 4 ,9,0 ,100};
    int n=sizeof(v)/sizeof(v[0]);

    // creating max heap with priority queue
    priority_queue<int ,vector<int> >pq(v , v+n);
    int k;
    cout<<"enter k \n";
    cin>>k;
    for(int i=0;i<k;i++){
        cout<<pq.top()<<" "; // give max value of heap
        pq.pop(); // will pop the max value from max heap
    }

    return 0;
}
