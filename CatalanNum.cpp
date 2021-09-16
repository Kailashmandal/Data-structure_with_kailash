#include<iostream>
using namespace std;
int Catalan(int n){
         if(n<=1){
             return 1; // C0 and C1 is fixed that is 1.
         }

         int res=0;
         for(int i=0;i<=n-1;i++){
             res+=Catalan(i)*Catalan(n-i-1);
         }

         return res;
     }
int main(int argc, char const *argv[])
{
    /*.. catalan numbers are sequence of integers like fibonaci 
      squence is = 1 ,1 , 2, ,5,14 ....

      we can actually use this number to find out number of bst possible with nth 
      catalan number.
      */

     for (size_t i = 0; i < 8; i++)
     {
         cout<<Catalan(i)<<" ";
         /* code */
     }
     

     // so if want to find out how many BSTs are possible from n nodes
     int n ;
     cin>>n;
     // just print nth catalan number
     cout<<"\n Possible number of BSTs from n nodes : "<<Catalan(n); 

    return 0;
}
