#include<bits/stdc++.h>
using namespace std;
//find median in running input stream of integers
priority_queue<int, vector<int> , greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insertion(int x){
/* if size is equal and top of max heap is smaller 
than push in max heap otherwise push in min heap */
if(pqmin.size()==pqmax.size()){
    if(pqmax.size()==0){
      pqmax.push(x);
      return ;
    }

    if(x<pqmax.top()){
        pqmax.push(x);
    }
    else pqmin.push(x);
}
else{
    if(pqmax.size()>pqmin.size()){
        if(x>=pqmax.top()){
            pqmin.push(x);
        }else{
            // if x < top of max heap
            int temp=pqmax.top();
            pqmax.pop();
            pqmin.push(temp); // push in min heap 
            pqmax.push(x); 
        }
    }else{
        if(x<=pqmin.top()){
            pqmax.push(x);
        }else{
            // if x > top of min heap
            int temp=pqmin.top();
            pqmin.pop();
            pqmax.push(temp);
            pqmin.push(x);
        }
    }
}

}
double findMedian(){ // median function 
    if(pqmin.size()==pqmax.size()){
        return (pqmin.top()+pqmax.top())/2.0 ;
    }
    else if(pqmin.size()>pqmax.size()){
        return pqmin.top();
    }
    else return pqmax.top();
}
int main(int argc, char const *argv[])
{
    while(1){  // stream of input 
        int k ;
        cin>>k;
    insertion(k);
    cout<<findMedian()<<endl;
    }
    return 0;
}
