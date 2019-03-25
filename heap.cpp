#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
void insert_heap(int value){
    int i;
    i=arr.size();
    arr.push_back(value);
    while(i>1 && arr[i/2]>arr[i]){
     swap(arr[i],arr[i/2]);
     i=i/2;
    }
}
void min_heapify(int index){
    int left,right,minimum;
    left=2*index;
    right=2*index+1;
    if(left < arr.size()&& arr[left]<arr[index])
    minimum=left;
    else minimum=index;
    if (right < arr.size() && arr[right] < arr[minimum])
      minimum = right;
   
    if(minimum!=index){
    swap(arr[minimum],arr[index]);
    min_heapify(minimum);
    }
}
void build_heap(){
    int i;
 
   for(i=arr.size()/2;i>0;i--){
       min_heapify(i);
    }
}
void delete_heap(int value){
    int i;
    vector<int>::iterator it; 
     
    for(i=1;i<arr.size();i++){
        if(arr[i]==value){
            it = arr.begin()+i;
            arr.erase(it);
            break;
        }
    }
//    for(i=1;i<arr.size();++i) cout<<arr[i]<<" "; cout<<endl;
    build_heap();
}

int main() {
    int q,i,x,n;
    cin>>q;
    arr.push_back(0);
    while(q--){
        cin>>n;
    if(n==1){ cin>>x; insert_heap(x);}
    if(n==2){cin>>x; delete_heap(x);}
    if(n==3) cout<<arr[1]<<"\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
