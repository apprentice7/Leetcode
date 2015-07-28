#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target){
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

int main(){
  Solution solution;
  std::vector<int> number(5);
  number[1] = 2;
  number[2] = 5;
  number[3] = 6;
  number[4] = 7;
  number[5] = 11; 
  std::vector<int> results(solution.twoSum(number, 18));
  cout << results[1] << " " << results[2] << endl;
  return 0;
}
