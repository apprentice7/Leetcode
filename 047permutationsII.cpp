// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 23-09-2015

/********************************************************************************** 
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
**********************************************************************************/

/*idea:
    based on permutation 1. 
    Every time sort the numbers after position,
    and pass those numbers that are equal
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int> > vv;
    vv.push_back(nums);

    if (nums.size() <2){
        return vv;
    }
        
    int pos=0;
    while(pos<nums.size()-1){
        int size = vv.size();
        for(int i=0; i<size; i++){

			sort(vv[i].begin()+pos, vv[i].end());

            for (int j=pos+1; j<vv[i].size(); j++) {
                vector<int> v = vv[i];
				if (v[j] == v[j-1]) continue;
				iter_swap(v.begin()+j,v.begin()+pos);
				vv.push_back(v);
            }
        }
        pos++;
    }
    return vv;
	}
};

/* //For testing
int main(){
	Solution test;
	int arr[] = {3,3,0,0,2,3,2};
	vector<int> v;
	v.assign(arr,arr+7);

	vector<vector<int> > re;
	re = test.permuteUnique(v);
	for(int i=0; i<re.size(); i++){
		for(int k=0; k<re[i].size(); k++){
			cout << re[i][k] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/
