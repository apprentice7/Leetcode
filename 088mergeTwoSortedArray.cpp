// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 05-11-2015

/********************************************************************************** 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n) 
*   to hold additional elements from B. The number of elements initialized in A and B 
*   are m and n respectively.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* for problem explaination: https://leetcode.com/discuss/66368/a-bug-in-testing-case */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=m-1;
      int j=n-1;
      int k = m+n-1;
        
      while(i >=0 && j>=0){
        if(nums1[i] > nums2[j])
          nums1[k--] = nums1[i--];
          else
            nums1[k--] = nums2[j--];
      }
      while(j>=0){
        nums1[k--] = nums2[j--];
		  }
    }
};

/*  This method can merge two sorted arrays into one sorted array
*   However, the question is kind of ambiguous that it requires m elements
*   in nums1 and n elements in nums2 to be sorted into an array which has
*   size of not less than m + n.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m < 1) nums1=nums2;
		int lower = 0;
		int upper = nums1.size()-1;
		while(nums2.size()>0){
			int middle;
			while(upper >= lower){
				middle = (upper+lower)/2;
				if(nums2.back() < nums1[middle]){
					upper = middle - 1;
				}
				else if(nums2.back() > nums1[middle]){
					lower = middle + 1;
				}
				else if(nums2.back() == nums1[middle]){
					break;
				}
			}
			if(nums2.back() >= nums1[middle]){
				nums1.insert(nums1.begin()+middle+1, nums2.back());
				nums2.pop_back();
			}
			else if(nums2[0] < nums1[middle]){
				nums1.insert(nums1.begin()+middle, nums2.back());
				nums2.pop_back();
			}
			upper = nums1.size() - 1;
			lower = middle;
		}
	}
};
*/

/* //For testing
int main(){
	Solution test;	
	int a[] = {5,6,6,7,9,10};
	int b[] = {11,12,12,13};
	vector<int> nums1;
	vector<int> nums2;
	nums1.assign(a,a+6);
	nums2.assign(b,b+4);

	test.merge(nums1,nums1.size(),nums2,nums2.size());

	for(int i=0; i< nums1.size(); i++){
		cout<< nums1[i] << endl;
	}
	return 0;
}
*/
