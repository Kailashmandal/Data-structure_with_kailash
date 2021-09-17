#include<bits/stdc++.h>
using namespace std;
 class Maxheap
 {

 public:
 int *arr;
 int size;
 int capacity;

     Maxheap(int cap){
      arr=new int[cap];
      capacity=cap;
      size=0;
     }
     int parentidx(int i){
         return (i-1)/2 ;
     }
     void swap(int *x ,int *y){
         int temp=*x;
         *x=*y;
         *y=temp;
     }

     void insert(int k){
         if(size>=capacity){
             cout<<" heap overflow";
             return ;
         }

         size++;
         int i=size-1;
         arr[i]=k;

         while(i!=0 && arr[parentidx(i)]<arr[i]){
             swap(&arr[parentidx(i)] , &arr[i]);
             i=parentidx(i);
         }
     }
     int left(int i){
         return (2*i+1);
     }

     int right(int i){
         return (2*i+2);
     }

     void Heapify(int i){
       int l=left(i);
       int r=right(i);
       int greater=i;

       if(l<size && arr[l]>arr[greater]){
           greater=l;
       }

       if(r<size && arr[r]> arr[greater]){
           greater=r;
       }

       if(greater!=i){
           swap(&arr[greater] , &arr[i]);
           Heapify(greater);
       }
     }

     int extractMax(){
         if(size==0) return -1;
         if(size==1){
             int t=arr[0];
             size--;
             return t;
         }

         int root=arr[0];
         size--;
         Heapify(0);
         return root;
     }
     int Size(){
         return size;
     }

     int Max(){
        return arr[0];
     }
    
 };
 int main(int argc, char const *argv[])
 {
     Maxheap h(10);
     h.insert(2);
     cout<<h.Max();
     return 0;
 }
 
 
