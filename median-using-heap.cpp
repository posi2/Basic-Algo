/*


You need two heaps: one min-heap and one max-heap. Each heap contains about one half of the data. Every element in the min-heap is greater or equal to the median, and every element in the max-heap is less or equal to the median.

When the min-heap contains one more element than the max-heap, the median is in the top of the min-heap. And when the max-heap contains one more element than the min-heap, the median is in the top of the max-heap.

When both heaps contain the same number of elements, the total number of elements is even. In this case you have to choose according your definition of median: a) the mean of the two middle elements; b) the greater of the two; c) the lesser; d) choose at random any of the two...

Every time you insert, compare the new element with those at the top of the heaps in order to decide where to insert it. If the new element is greater than the current median, it goes to the min-heap. If it is less than the current median, it goes to the max heap. Then you might need to rebalance. If the sizes of the heaps differ by more than one element, extract the min/max from the heap with more elements and insert it into the other heap.

In order to construct the median heap for a list of elements, we should first use a linear time algorithm and find the median. Once the median is known, we can simply add elements to the Min-heap and Max-heap based on the median value. Balancing the heaps isn't required because the median will split the input list of elements into equal halves.

If you extract an element you might need to compensate the size change by moving one element from one heap to another. This way you ensure that, at all times, both heaps have the same size or differ by just one element.

*/
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
