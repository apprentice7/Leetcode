// Source : https://oj.leetcode.com/problems/
// Author : Tony
// Date   : 17-08-2015

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* Note:
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
*     For example, given array S = {-1 0 1 2 -1 -4},
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
*            
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	int times = 0;
		  vector<int> negative;
    	vector<int> positive;
    	vector<int>::iterator Nit = negative.begin();
    	vector<int>::iterator Pit = positive.begin();
    	vector<vector<int> > output;
    	
    	for(int i=0; i< nums.size(); i++){
    		if(nums[i] < 0) {
    			Nit = negative.insert(Nit,nums[i]);
    		}
    		else {
    			Pit = positive.insert(Pit,nums[i]);
    		}
    	}
    	//cout << negative[0] << negative[1] << negative[2] << endl;   
    	//cout << positive[0] << positive[1] << positive[2] << positive[3] << endl;
		  
		  //three "0"
	  	for(int z=0; z<positive.size();z++){
	  		if (positive[z] == 0){
	  			times++;
	  		}
	  	}
	  	if(times>=3){
		  	int arr[]={0,0,0};
		  	vector<int> tempout;
		  	tempout.assign(arr,arr+3);
		  	output = OutputInsert(output,tempout);
		  }
    	
    	//two negative + one positive
    	for(int n1=0; n1<negative.size()-1;n1++){
    		for(int n2=n1+1;n2<negative.size();n2++){
    			for(int p1=0;p1<positive.size();p1++){
    				if(negative[n1] + negative[n2] + positive[p1] == 0){
    					vector<int> tempout;
    					if(negative[n1] < negative[n2]){
    						tempout.insert(tempout.begin(),positive[p1]);
    						tempout.insert(tempout.begin(),negative[n2]);
    						tempout.insert(tempout.begin(),negative[n1]);
    						output = OutputInsert(output,tempout);
    						//cout << tempout[0] << tempout[1] << tempout[2] << endl;
    					}
    					else{
    						tempout.insert(tempout.begin(),positive[p1]);
    						tempout.insert(tempout.begin(),negative[n1]);
    						tempout.insert(tempout.begin(),negative[n2]);
    						output = OutputInsert(output,tempout);
    						//cout << tempout[0] << tempout[1] << tempout[2] << endl;
    					}
    				}
    			}
    		}
    	}
		  
		  //two positive + one negative
    	for(int p1=0; p1<positive.size()-1;p1++){
    		for(int p2=p1+1;p2<positive.size();p2++){
    			for(int n1=0;n1<negative.size();n1++){
    				if(positive[p1] + positive[p2] + negative[n1] == 0){
    					vector<int> tempout;
    					if(positive[p1] < positive[p2]){
    						tempout.insert(tempout.begin(),positive[p2]);
    						tempout.insert(tempout.begin(),positive[p1]);
    						tempout.insert(tempout.begin(),negative[n1]);
    						output = OutputInsert(output,tempout);
    						//cout << tempout[0] << tempout[1] << tempout[2] << endl;
    					}
    					else{
    						tempout.insert(tempout.begin(),positive[p1]);
    						tempout.insert(tempout.begin(),positive[p2]);
    						tempout.insert(tempout.begin(),negative[n1]);
    						output = OutputInsert(output,tempout);
    						//cout << tempout[0] << tempout[1] << tempout[2] << endl;
    					}
    				}
    			}
    		}
    	}
    	return output;
    }
private:
	vector<vector<int> > OutputInsert(vector<vector<int> > out, vector<int> temp){
		int x = out.size();
		if (x == 0){
			out.insert(out.begin(),temp);
			return out;
		}
		for(int i=0; i<x; i++){
			if(out[i] == temp){
				return out;
			}
		}
		out.insert(out.begin(),temp);
		return out;
	}
};
/* //For testing
int main(){
	int a[] = {-1, 0, -2, -3, 1, 0, 3, -5, 8, 2, 10, 0};
	//int a[] = {-1, 0, 1, 2, -1, 1, -4};
	//int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
	
	Solution s;
    vector<int> n(a, a+sizeof(a)/sizeof(int));
    vector< vector<int> > result = s.threeSum(n);
	for(int t=0; t<result.size();t++){
		cout << result[t][0] << result[t][1] << result[t][2] << endl;
	}
	return 0;
}
*/
