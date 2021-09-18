#include<bits/stdc++.h>
using namespace std;

// minimum size subsequence with sum k of an array
int main(int argc, char const *argv[])
{
    int n,k;
    cout<<"enter the size of array : ";

    cin>>n;

    cout<<"enter the key : ";
    cin>>k;
    cout<<"enter the elements of array :";
    vector<int> v(n);
    for(int i=0;i< n;++i){
        int k;
        cin>>k;
        v.push_back(k);
    }
    priority_queue<int , vector<int>> pq(v.begin(),v.end());
    int sum=0;
    int c=0;
    while (!pq.empty())
    {
        sum+=pq.top();
        c++;
        pq.pop();

        if(sum>=k){
            break;
        }
        /* code */
    }

    if(sum<k) cout<<"no such subsequence";
    else cout<<"the minimum size of subsequence is : "<<c;
    
    return 0;
}
