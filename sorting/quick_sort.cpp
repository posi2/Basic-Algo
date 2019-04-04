#include <bits/stdc++.h>
using namespace std;

 int random_partition(int a[],int p, int r){
   
   int k=p,pivot,i;
   int random_index=(rand()%(r-p))+p;
   pivot=a[random_index];
   swap(a[random_index],a[r]); // to set pivot at end

   for(i=p;i<=r;i++){
    //   cout<<a[i]<<" "<<i<<" "<<k<<endl;
     if(a[i]<=pivot){ swap(a[i],a[k]); k++;}
   }
   return k-1;
 }
void quick_sort(int a[],int p,int r){
   if(p>=r) return;   // base cse
   int q=random_partition(a,p,r);
  // cout<<p<<" "<<q<<" "<<r<<endl;
   quick_sort(a,p,q-1);
   quick_sort(a,q+1,r);
 }
 int main(){
   int a[]={5,8,6,4,1,6,4};
   quick_sort(a,0,6);
   for(int i=0;i<5;i++) cout<<a[i]<<" ";
   return 0;
 }
