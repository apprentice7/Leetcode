// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Tony
// Date   : 30-07-2015

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/

/*
This problem is hard. The answer is duplicated from: https://leetcode.com/discuss/35275/c-implementation-o-log-m-n-with-vector-int-as-parameters
This problem needs more review in weekend.
*/

#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int size_1 = nums1.size();
    const int size_2 = nums2.size();
    int k = (size_1 + size_2) / 2;
    int res1 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k+1);
    if ((size_1 + size_2) % 2 == 0) {
        int res2 = Kth(nums1.begin(), size_1, nums2.begin(), size_2, k);
        return ( (double) res1 + res2) / 2.0;
    }
    return res1;
}
private:
  typedef vector<int>::iterator Iter;

  int  Kth(Iter start1, int size_1, Iter start2, int size_2, int kth) {
    if (size_1 > size_2) return Kth(start2 , size_2, start1, size_1, kth);
    if (size_1 == 0) return *(start2 + kth - 1);
    if (kth == 1) return min(*start1, *start2);

    int index_1 = min(size_1, kth / 2);
    int index_2 = kth - index_1;
    if (*(start1 + index_1 - 1) > *(start2 + index_2 - 1)) 
        return Kth(start1, size_1 ,start2 + index_2, size_2 - index_2, kth - index_2);
    return Kth(start1 + index_1, size_1 - index_1, start2, index_2, kth - index_1);
}

