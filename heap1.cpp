#include<bits/stdc++.h>
using namespace std;

void swap(int *x ,int * y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

class Minheap{
public:
  int *hrr; // pionter to array of heap
  int cap; // capacity of the heap
  int size ; // size of the heap
  
  Minheap(int capacity){
      hrr=new int[capacity];
      cap=capacity;
      size=0;
  }

  int parentIdx(int i){
      return (i-1)/2;
  }
 
 void insert(int key){
     if(size==cap){
         cout<<"heap overflow ! ";
         return ;
     }

     size++;
     int i=size-1;
     hrr[i]=key;

     // fix the min heap if property is voilated
     while(i!=0 && hrr[parentIdx(i)] > hrr[i]){
         swap(&hrr[i] ,&hrr[parentIdx(i)]);
         i=parentIdx(i);
     }
 }
 int left(int i){
     return 2*i+1;
 }
 int right(int i){
     return 2*i+2;
 }

 void Heapify(int i){
     int l=left(i);
     int r=right(i);
     int smallest=i;
     
     // chcek for left child
     if(l<size && hrr[l]<hrr[i]){
         smallest=l;
     } 

     //check for right child
     if(r< size && hrr[l]<hrr[i]){
         smallest=r;
     }

     if(smallest!=i){
          swap(&hrr[i],&hrr[smallest]);
          Heapify(smallest);
     }
 }

 int extractMin(){
     if(size<=0) return -1;

     if(size==1) {
         int temp=hrr[0];
         size--;
         return temp;
         
     }

     int root=hrr[0];
     hrr[0]=hrr[size-1];
     size--;
     Heapify(0);
     return root;
 }

 int Size(){
     return size;
 }

int minimum(){
    return hrr[0];
}

};
int main(int argc, char const *argv[])
{
    Minheap h(10);
    h.insert(2);
    h.insert(3);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    h.insert(1);
    h.insert(10);
    h.insert(9);
    h.insert(8);
    h.insert(7);
  cout<<"printing heap\n";
  for(int i=0;i<10;i++){
      cout<<h.extractMin()<<" ";
  }

    return 0;
}
