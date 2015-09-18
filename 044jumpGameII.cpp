#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
		int output = 0;
		if(n<1) return 0;

		found(nums, n-1, output);
		return output;
    }
	void found(vector<int>& nums, int pos, int& count){
		int nPos = -1;
		int i = pos-1;
		int temp = -1;
		for(; i>0; i--){
			if(nums[i] >= (pos-i)){
				nPos = i;
				temp = nums[i];
			}
			while(nums[i] <= temp && i>0){
				i--;
			}
		}
		if(nPos > 0) {
			count++;
			found(nums, nPos, count);
		}
		else{
			count++;
			return;
		}
	}
};

 //For testing
int main(){
	Solution test;
	int arr[] = {1,1,1,1,1};
	vector<int> v;
	v.assign(arr,arr+5);
	cout << test.jump(v) << endl;

	return 0;
}
