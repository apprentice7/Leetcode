// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Tony
// Date   : 28-07-1015

/********************************************************************************** 
* 
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target, 
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
* 
*               
**********************************************************************************/


#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target){
    int i = 0;
    int j = 0;
    std::vector<int> re(2);
    for(i=1;i<nums.size()+1;i++){
      for(j=i+1;j<nums.size()+1;j++){
        if((nums[i]+nums[j]) == target){
          re[1] = i;
          re[2] = j;
            return re;
        }
      }
    }
  }
};

/* For testing
int main(){
  Solution solution;
  std::vector<int> number(4);
  number[1] = 2;
  number[2] = 7;
  number[3] = 11;
  number[4] = 5;
  std::vector<int> results(solution.twoSum(number, 9));
  cout << results[1] << " " << results[2] << endl;
  return 0;
}
*/
