#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   unordered_map<int, int> m;   // map with unsorter keys
    
   for (auto it=m.begin(); it != m.end(); ++it)
   {
      cout << it->first << " " << it->second<<"\n";   // basic iteration to see all th key-value pair of the map
    }
    
    return 0;
}
  
