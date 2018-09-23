#include <bits/stdc++.h> // brute force method//
using namespace std;
#define ll long long

int main() {
  ll n,i,j,md,mi,cmd,cmi,c1,c;
  cin>>n;
  ll a[n];
  for(i=0;i<n;++i) cin>>a[i];
  md=2000;
  mi=1000000;
  for(i=0;i<n;++i)
  {
      cmd=md; cmi=i; c1=0;
      for(j=i;j<n;++j)
      {
          if(a[j]<cmd){
              cmd=cmd-a[j];
              cmi=cmi*a[j];
              if(cmd>=0&&cmi<=mi) ++c1;
          }
          c=max(c1,c);
      }
  }
  cout<<"Maximum possible"<<c;
}
