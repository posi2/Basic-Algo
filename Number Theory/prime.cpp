
#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    if(n<=1) return 0;
    else if(n==2||n==3) return 1;
    else if(n%2==0||n%3==0) return 0;
    else{for(int i=5;i<=sqrt(n);){
            if(n%i==0||n%(i+2)==0) return 0; // since prime number in pair 6n+1 and 6n-1 except 2 and 3.
            i+=6;
        }
    return 1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin>>t;
    while(t--){
        int c;
        cin>>n;
        c=prime(n);
        if(c==0) cout<<"Not prime\n";
        else cout<<"Prime\n";
        
    }
    return 0;
}
