# include<bits/stdc++.h>
using namespace std;
# define INF 1000000007
int n;
int sum_query(int a,int b,int *segment_tree ){
    a+=n;
    b+=n;
    int sum=0; 
    while(a<=b){
       if(a%2==1) sum+=segment_tree[a++];
       if(b%2==0) sum+=segment_tree[b--];
       a/=2;
       b/=2;
    }
    return sum;
}
int main(){
    int i,a,b;
    cin>>n;
    int segment_tree[2*n];
    for(i=n;i<=2*n;++i) cin>>segment_tree[i];

    for(i=n-1;i>0;--i) segment_tree[i]=segment_tree[2*i]+segment_tree[2*i+1];
	
    cout<<"Your segment_tree is\n";
    for(i=1;i<2*n;++i) cout<<segment_tree[i]<<" ";
    cin>>a>>b;
    cout<<"\nsum of range a to b is "<<sum_query(a,b,segment_tree);
    return 0;
}
