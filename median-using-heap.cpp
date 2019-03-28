
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> min_arr, max_arr;
float median;
void insert_min_heap(int value) {
  int i;
  i = min_arr.size();
  min_arr.push_back(value);
  while (i > 1 && min_arr[i / 2] > min_arr[i]) {
    swap(min_arr[i], min_arr[i / 2]);
    i = i / 2;
  }
}
void insert_max_heap(int value) {
  int i;
  i = max_arr.size();
  max_arr.push_back(value);
  while (i > 1 && max_arr[i / 2] < max_arr[i]) {
    swap(max_arr[i], max_arr[i / 2]);
    i = i / 2;
  }
}
void min_heapify(int index) {
  int left, right, minimum;
  left = 2 * index;
  right = 2 * index + 1;
  if (left < min_arr.size() && min_arr[left] < min_arr[index])
    minimum = left;
  else
    minimum = index;
  if (right < min_arr.size() && min_arr[right] < min_arr[minimum])
    minimum = right;

  if (minimum != index) {
    swap(min_arr[minimum], min_arr[index]);
    min_heapify(minimum);
  }
}
void max_heapify(int index) {
  int left, right, maximum;
  left = 2 * index;
  right = 2 * index + 1;
  if (left < max_arr.size() && max_arr[left] > max_arr[index])
    maximum = left;
  else
    maximum = index;
  if (right < max_arr.size() && max_arr[right] > max_arr[maximum])
    maximum = right;

  if (maximum != index) {
    swap(max_arr[maximum], max_arr[index]);
    max_heapify(maximum);
  }
}
void extract_max() {
  int value;
  //  cout<<max_arr[1]<<" "<<max_arr[(max_arr.size()-1)]<<endl;
  value = max_arr[1];
  swap(max_arr[1], max_arr[(max_arr.size() - 1)]);
  max_arr.pop_back();
  max_heapify(1);
  insert_min_heap(value);
  //    for(i=1;i<arr.size();++i) cout<<arr[i]<<" "; cout<<endl;
}
void extract_min() {
  int value;
  value = min_arr[1];
  swap(min_arr[1], min_arr[(min_arr.size() - 1)]);
  min_arr.pop_back();
  min_heapify(1);
  insert_max_heap(value);
  //    for(i=1;i<arr.size();++i) cout<<arr[i]<<" "; cout<<endl;
}

int main() {
  int q, x, s1, s2;
  cin >> q;
  min_arr.push_back(0);
  max_arr.push_back(0);
  cin >> x;
  median = x;
  min_arr.push_back(x);
  while (--q) {
    cout << fixed << setprecision(1) << median << "\n";
    cin >> x;
    if (x >= median)
      insert_min_heap(x);
    else
      insert_max_heap(x);
    s1 = max_arr.size();
    s2 = min_arr.size();
    //    cout<<max_arr.size()-1<<" "<<min_arr.size()-1<<"\n";
    if (s1 > s2 + 1)
      extract_max();
    if (s1 < s2 - 1)
      extract_min();
    float m1 = min_arr[1];
    float m2 = max_arr[1];
    //   cout<<m1<<" "<<m2<<endl;
    if (max_arr.size() - min_arr.size() == 0)
      median = (m1 + m2) / 2;
    else if (max_arr.size() - min_arr.size() == 1)
      median = max_arr[1];
    else
      median = min_arr[1];
  }
  cout << fixed << setprecision(1) << median << "\n";
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}
