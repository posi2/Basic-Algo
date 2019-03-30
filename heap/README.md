## Heap
### Calculation Of Median using Heap
You need two heaps: one min-heap and one max-heap. Each heap contains about one half of the data. Every element in the min-heap is greater or equal to the median, and every element in the max-heap is less or equal to the median.

When the min-heap contains one more element than the max-heap, the median is in the top of the min-heap. And when the max-heap contains one more element than the min-heap, the median is in the top of the max-heap.

When both heaps contain the same number of elements, the total number of elements is even. In this case you have to choose according your definition of median: a) the mean of the two middle elements; b) the greater of the two; c) the lesser; d) choose at random any of the two...

Every time you insert, compare the new element with present median in order to decide where to insert it. If the new element is greater than the current median, it goes to the min-heap. If it is less than the current median, it goes to the max heap. Then you might need to rebalance. If the sizes of the heaps differ by more than one element, extract the min/max from the heap with more elements and insert it into the other heap.

In order to construct the median heap for a list of elements, we should first use a linear time algorithm and find the median. Once the median is known, we can simply add elements to the Min-heap and Max-heap based on the median value. Balancing the heaps isn't required because the median will split the input list of elements into equal halves.

If you extract an element you might need to compensate the size change by moving one element from one heap to another. This way you ensure that, at all times, both heaps have the same size or differ by just one element.

**Time Complexity  O(n logn)**

**Space Complexity  O(n)**

Note: Using priority queue in STL, we implement the function in shorter way.
