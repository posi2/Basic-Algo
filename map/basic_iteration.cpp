#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   unordered_map<int, int> m;   // map with unsorted keys
   
   int element,no_of_element;
   
   cin>>no_of_element;
   
   for(int i = 0;i < no_of_element; ++i){ cin>>element; m[element]++;} //insertion of the keys and it's frequency;
    
   for (auto it = m.begin(); it != m.end(); ++it)
   {
      cout << it->first << " " << it->second<<"\n";   // basic iteration to see all th key-value pair of the map
    }
    
    return 0;
}
  
