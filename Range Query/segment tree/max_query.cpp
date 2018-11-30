# include<bits/stdc++.h>
using namespace std;
# define INF 1000000007
int n;
int max_query(int a,int b,int *segment_tree ){
    a+=n;
    b+=n;
   
    int maxa=-INF; 
    while(a<=b){
       if(a%2==1) maxa=max(maxa,segment_tree[a++]);
       if(b%2==0) maxa=max(maxa,segment_tree[b--]);
       a/=2;
       b/=2;
    }
    return maxa;
}
int main(){
    int i,a,b;
    cin>>n;
    int segment_tree[2*n];
    for(i=n;i<2*n;++i) cin>>segment_tree[i];

    for(i=n-1;i>0;--i) segment_tree[i]=max(segment_tree[2*i],segment_tree[2*i+1]);
	
    cout<<"Your segment_tree is\n";
    for(i=1;i<2*n;++i) cout<<segment_tree[i]<<" ";
    cin>>a>>b; // range work in 0 indexing
    cout<<"\nmaximum of range a to b is "<<max_query(a,b,segment_tree);
    return 0;
}
