#include <bits/stdc++.h>
using namespace std;

int main() {
    int key,l,r,m,j=-1,i,n;
    cout<<"Enter the no. of values to be inserted\n";
    cin>>n;
    int a[n];
    for(i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
	l=0; r=n-1;
	cout<<"Enter the value to search\n";
	cin>>key;
	while(l!=r&&j==-1)
	{
	    m=(l+r)/2;
	    if(key==a[m]){ i=m; j=0; }
	    else if(key>a[m]) l=m;
	    else r=m;
	}
	if(j==0) cout<<"Value "<<key<<" found on "<<i+1<<" position";
	else cout<<"Value not found";
	return 0;
}
